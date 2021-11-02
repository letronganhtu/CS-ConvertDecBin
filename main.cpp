#include <iostream>
#include <string>
#include <regex>
using namespace std;

/// <summary>
/// Convert from Binary to Integer 8 bit in Decimal (include Unsigned and Signed)
/// </summary>
class BinaryTo8BitInteger {
private:
    string _binarySequence;

public:
    BinaryTo8BitInteger(string binary) {
        _binarySequence = binary;
        if (_binarySequence.length() > 8) {
            _binarySequence = _binarySequence.substr(_binarySequence.length() - 8, 8);
        }
        else if (_binarySequence.length() < 8) {
            while (_binarySequence.length() != 8) {
                _binarySequence = "0" + _binarySequence;
            }
        }
    }

public:
    /// <summary>
    /// Check if the input string is a binary sequence or not
    /// </summary>
    bool isValid() {
        const string pattern = "\\b[0,1]*\\b";
        regex validBinary(pattern);
        
        bool result = regex_match(_binarySequence, validBinary);
        return result;
    }

    int convertToSignedInteger() {
        
    }
};

int main() {
    string binarySequence;
    cin >> binarySequence;
    BinaryTo8BitInteger p(binarySequence);
    return 0;
}
