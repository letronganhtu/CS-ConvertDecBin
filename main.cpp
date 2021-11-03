#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

// Check if the input string is a format of binary sequence or not
class CheckBinarySequence {
public:
    bool isValid(string bin) {
        // Binary sequence contains only '0' and '1' character
        const string pattern = "\\b[0,1]*\\b";
        regex validBinary(pattern);
        
        bool result = regex_match(bin, validBinary);
        return result;
    }
};

// User know what they have just entered into program
class InputRepresentation {
public:
    static string represent(int numBit, string bin) {
        stringstream out;
        out << "Your input binary sequence in " << numBit << " bit is: ";

        for (int i = 0; i < numBit; i++) {
            if (i != numBit - 1 && i % 4 == 3) {
                out << bin[i] << "'";
            }
            else {
                out << bin[i];
            }
        }
        string result = out.str();
        return result;
    }
};

// Convert from Binary to Integer 8/16/32 bits in Decimal (include Unsigned and Signed)
class BinaryToInteger {
private:
    int _numberOfBit; // Number of bits in string, it can be 8, 16 or 32 depend on user
    string _binarySequence; // Represent bit sequence in a string

public:
    // Require user must initialize 2 value as parameter above in constructor
    BinaryToInteger(int number, string binary) {
        _numberOfBit = number;
        _binarySequence = binary;

        if (_binarySequence.length() > _numberOfBit) { // The length of a string is longer than number of bits
            // Take the sub sequence from right to left until its length equal to number of bits
            _binarySequence = _binarySequence.substr(_binarySequence.length() - _numberOfBit, _numberOfBit);
        }
        else if (_binarySequence.length() < _numberOfBit) { // The length of a string is shorter than number of bits
            while (_binarySequence.length() != _numberOfBit) {
                // Add '0' into the first index of the sequence until its length equal to number of bits
                _binarySequence = "0" + _binarySequence;
            }
        }
    }

public:
    int numberOfBit() { return _numberOfBit; }
    string binarySequence() { return _binarySequence; }
        
public:
    unsigned int convertToUnsignedInteger() {
        unsigned int res = 0;

        for (int i = 0; i < _numberOfBit; i++) {
            if (_binarySequence[i] == '1') {
                res += pow(2, _numberOfBit - 1 - i);
            }
        }

        return res;
    }

    int convertToSignedInteger() {
        if (_binarySequence[0] == '0') {
            return convertToUnsignedInteger();
        }
        else {
            int res = 0;
            for (int i = 0; i < _numberOfBit; i++) {
            if (_binarySequence[i] == '1') {
                _binarySequence[i] = '0';
            }
            else _binarySequence[i] = '1';
        }
        if (_binarySequence[_numberOfBit - 1] == '0') {
            _binarySequence[_numberOfBit - 1] == '1';
        }
        else {
            int idx = _numberOfBit - 1;
            _binarySequence[idx] = '0';
            while (true) {
                idx--;
                if (_binarySequence[idx] == '0') {
                    _binarySequence[idx] = '1';
                    break;
                }
                else _binarySequence[idx] = '0';
            }
        }
        res = -convertToUnsignedInteger();

        return res;
        }
    }
};

class BinaryToFloatingPoint {
private:
    int _numberOfBit; // Number of bits in string, it can be 32 or 64 bits depend on user
    string _binarySequence; // Represent bit sequence in a string

public:
    BinaryToFloatingPoint(int number, string binary) {
        _numberOfBit = number;
        _binarySequence = binary;

        if (_binarySequence.length() > _numberOfBit) { // The length of a string is longer than number of bits
            // Take the sub sequence from right to left until its length equal to number of bits
            _binarySequence = _binarySequence.substr(_binarySequence.length() - _numberOfBit, _numberOfBit);
        }
        else if (_binarySequence.length() < _numberOfBit) { // The length of a string is shorter than number of bits
            while (_binarySequence.length() != _numberOfBit) {
                // Add '0' into the first index of the sequence until its length equal to number of bits
                _binarySequence = "0" + _binarySequence;
            }
        }
    }

public:
    double convertToSinglePrecisionFloat() {
        double res = 0;

        string exponent = _binarySequence.substr(1, 8);
        BinaryToInteger bti(8, exponent);
        int exp = bti.convertToUnsignedInteger() - 127;

        res += pow(2, exp);
        
        string mantissa = _binarySequence.substr(9, 23);
        for (int i = 0; i < mantissa.length(); i++) {
            if (mantissa[i] == '1') {
                res += pow(2, exp - 1 - i);
            }
        }

        if (_binarySequence[0] == '1') res = -res;

        return res;
    }

    double convertToDoublePrecision() {
        double res = 0;

        string exponent = _binarySequence.substr(1, 11);
        BinaryToInteger bti(16, exponent);
        int exp = bti.convertToUnsignedInteger() - 1023;

        res += pow(2, exp);
        
        string mantissa = _binarySequence.substr(12, 52);
        for (int i = 0; i < mantissa.length(); i++) {
            if (mantissa[i] == '1') {
                res += pow(2, exp - 1 - i);
            }
        }

        if (_binarySequence[0] == '1') res = -res;

        return res;
    }
};

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a){
    for(int i = 0; i < a.size(); ++i)
        out << a[i];
    return out;
}

template<class T>
vector<T> operator~(const vector<T>& a){
    vector<T> out(a.size());
    for(int i = 0; i < a.size(); ++i)
        out[i] = a[i] ^ 1;
    return out;
}

template<class T>
vector<T>& operator++(vector<T>& a, int ){
    int r = 0;
    a[a.size() - 1] ++;
    r = a.back() / 2;
    a[a.size() - 1] %= 2;
    for(int i = a.size() - 2; i >= 0; --i){
        a[i] += r;
        r = a[i] / 2;
        a[i] %= 2;
    }
    return a;
}

template<class T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b){
    for(int i = 0; i < b.size(); ++i)
        a.push_back(b[i]);

    return a;
}

class Math{
    public:
        static unsigned long long mpow(unsigned long long x, int y){
            unsigned long long res = 1;
            while(y){
                if(y & 1)
                    res *= x;
                y >>= 1;
                x *= x;
            }
            return res;
        }
};

class IntegerToBin{
    public:
        static vector<int> toBit(const long long &d){
            vector<int> res;
            res.clear();
       
            long long _d = abs(d);
            for(; _d; _d >>= 1)
                res.push_back((_d & 1 ? 1 : 0));

            reverse(res.begin(), res.end());

            return res;
        }

        static vector<int> to64Bit(const long long &d){
            vector<int> res;
            res.clear();
            long long _d = abs(d);
            for(; _d; _d >>= 1){
                res.push_back((_d & 1 ? 1 : 0));
            }
            for(int i = res.size(); i <= 63; ++i)
                res.push_back(0);

            reverse(res.begin(), res.end());
            return res;
        }

        static vector<int> to8Bit(const long long &d){
            vector<int> res = to64Bit(d);
            
            return vector<int>(res.begin() + 64 - 8, res.end());
        }

        static vector<int> to11Bit(const long long &d){
            vector<int> res = to64Bit(d);

            return vector<int>(res.begin() + 64 - 11, res.end());
        }

        static vector<int> to16Bit(const long long &d){
            vector<int> res = to64Bit(d);

            return vector<int>(res.begin() + 64 - 16, res.end());
        }

        static vector<int> to32Bit(const long long &d){
            vector<int> res = to64Bit(d);

            return vector<int>(res.begin() + 64 - 32, res.end());
        }

        static vector<int> to2s8Bit(const long long &d){
            vector<int> a = to8Bit(d);
            if(d < 0){
                a = ~a;
                a++;
            }
            if((long long)(1 << 8)- 1 <= abs(d))
                throw runtime_error("over size of 8bits");
            
            return a;
        }

        static vector<int> to2s16Bit(const long long &d){
            vector<int> a = to16Bit(d);
            if(d < 0){
                a = ~a;
                a++;
            }
            if((long long)(1 << 16) - 1 <= abs(d))
                throw runtime_error("over size of 16bits");
            
            return a;
        }

        static vector<int> to2s32Bit(const long long &d){
            vector<int> a = to32Bit(d);
            if(d < 0){
                a = ~a;
                a++;
            }
            if((long long)(1 << 32) - 1 <= abs(d))
                throw runtime_error("over size of 32bits");

            return a;
        }
};

class DoubleToBin{
    public:
        static vector<int> to32Bit(const double& b){
            long long _b = (long long)b;
            vector<int> getBit = IntegerToBin::toBit(_b); 
            int need = 24 - getBit.size();
            _b =(long long) (b * Math::mpow(2, need));
            vector<int> man = IntegerToBin::toBit(_b);
            int e = 127 + 23 - need; 
            vector<int> res;
            res.push_back(b < 0 ? 1 : 0);
            res += IntegerToBin::to8Bit(e);
            res += vector<int>(man.begin() + 1, man.end());

            return res;
        }

        static vector<int> to64Bit(const double& b){
            unsigned long long _b = (unsigned long long)b;
            vector<int> getBit = IntegerToBin::toBit(_b); 
            int need = 53 - getBit.size();
            _b = (unsigned long long)(b * Math::mpow(2, need));
            vector<int> man = IntegerToBin::toBit(_b);
            int e = 1023 + 52 - need;
            vector<int> res;
            res.push_back(b < 0 ? 1 : 0);
            res += IntegerToBin::to11Bit(e);
            res += vector<int>(man.begin() + 1, man.end());

            return res;
        }
};

int main() {
    string binarySequence;
    cin >> binarySequence;
    /*BinaryToInteger bti(8, binarySequence);
    cout << InputRepresentation::represent(bti.numberOfBit(), bti.binarySequence()) << endl;
    cout << bti.convertToUnsignedInteger() << endl;
    cout << bti.convertToSignedInteger();*/
    BinaryToFloatingPoint btf(64, binarySequence);
    cout << btf.convertToDoublePrecision();

    double x;
    cin >> x;
    
    bitset<64> b(x);
    cout << b.to_string() << '\n';

    cout << DoubleToBin::to32Bit(x);
    cout << '\n' << DoubleToBin::to64Bit(x);

    return 0;
}