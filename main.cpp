#include <iostream>
#include <string>
#include <regex>
#include <cmath>
using namespace std;

// Convert from Binary to Integer 8/16/32 bits in Decimal (include Unsigned and Signed)
class BinaryToInteger {
private:
    int _numberOfBit; // Number of bits in string
    string _binarySequence; // Represent bit sequences in a string

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

// Edit tomorrow
public:
    // Check if the input string is a binary sequence or not
    bool isValid() {
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

int main() {
    string binarySequence;
    cin >> binarySequence;
    BinaryTo8BitInteger p(binarySequence);
    cout << p.convertToSignedInteger() << endl;
    cout << p.convertToUnsignedInteger();
    return 0;
}