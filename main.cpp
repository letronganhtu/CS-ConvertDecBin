#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <sstream>
using namespace std;

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
    // User know what they entered in program
    string toString() {
        stringstream out;
        out << "Your input binary sequence in " << _numberOfBit << " bit: ";

        for (int i = 0; i < _binarySequence.length(); i++) {
            if (i != _binarySequence.length() - 1 && i % 4 == 3) {
                out << _binarySequence[i] << "'";
            }
            else {
                out << _binarySequence[i];
            }
        }

        string result = out.str();
        return result;
    }

public:
    // Check if the input string is a format of binary sequence or not
    bool isValid() {
        // Binary sequence contains only '0' and '1' character
        const string pattern = "\\b[0,1]*\\b";
        regex validBinary(pattern);
        
        bool result = regex_match(_binarySequence, validBinary);
        return result;
    }

    int convertToSignedInteger() {
        int res = 0;

        for (int i = 0; i < _binarySequence.length(); i++) {
            if (_binarySequence[i] == '1') {
                if (i == 0) res = -pow(2, _binarySequence.length() - 1);
                else res += pow(2, _binarySequence.length() - 1 - i);
            }
        }

        return res;
    }

    unsigned int convertToUnsignedInteger() {
        unsigned int res = 0;

        for (int i = 0; i < _binarySequence.length(); i++) {
            if (_binarySequence[i] == '1') {
                res += pow(2, _binarySequence.length() - 1 - i);
            }
        }

        return res;
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
    // Check if the input string is a format of binary sequence or not
    bool isValid() {
        // Binary sequence contains only '0' and '1' character
        const string pattern = "\\b[0,1]*\\b";
        regex validBinary(pattern);
        
        bool result = regex_match(_binarySequence, validBinary);
        return result;
    }

    float convertToSinglePrecisionFloat() {
        float res = 0;

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

int main() {
    string binarySequence;
    cin >> binarySequence;
    BinaryToFloatingPoint btf(64, binarySequence);
    cout << btf.convertToDoublePrecision();

    return 0;
}