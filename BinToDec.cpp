#include <regex>
#include <cmath>

#include "BinToDec.h"

bool CheckBinarySequence::isValid(string bin) {
    // Binary sequence contains only '0' and '1' character
    const string pattern = "\\b[0,1]*\\b";
    regex validBinary(pattern);
        
    bool result = regex_match(bin, validBinary);
    return result;
}

BinaryToInteger::BinaryToInteger(int number, string binary) {
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

int BinaryToInteger::numberOfBit() const { return _numberOfBit; }
string BinaryToInteger::binarySequence() const { return _binarySequence; }
        
unsigned int BinaryToInteger::convertToUnsignedInteger() {
    unsigned int res = 0;
    int idx = 0;

    for (int i = _numberOfBit - 1; i >= 0; i--) {
        if (_binarySequence[i] == '1') {
            res += pow(2, idx);
        }
        idx++;
    }

    return res;
}

int BinaryToInteger::convertToSignedInteger() {
    int res = (_binarySequence[0] == '1') ? -pow(2, _numberOfBit - 1) : 0;
    int idx = 0;

    for (int i = _numberOfBit - 1; i > 0; i--) {
        if (_binarySequence[i] == '1') res += pow(2, idx);
        idx++;
    }

    return res;
}

BinaryToFloatingPoint::BinaryToFloatingPoint(int number, string binary) {
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

int BinaryToFloatingPoint::numberOfBit() const { return _numberOfBit; }
string BinaryToFloatingPoint::binarySequence() const { return _binarySequence; }

float BinaryToFloatingPoint::convertToSinglePrecisionFloat() {
    const int sign = 1;
    const int expo = 8;
    const int mantis = 23;
    float res = 0;

    string exponent = _binarySequence.substr(1, expo);
    BinaryToInteger bti(8, exponent);
    int exp = bti.convertToUnsignedInteger() - 127;
    res += pow(2, exp);

    string mantissa = _binarySequence.substr(9, mantis);
    for (int i = 0; i < mantis; i++) {
        if (mantissa[i] == '1') {
            res += pow(2, exp - 1 - i);
        }
    }

    if (_binarySequence[0] == '1') res = -res;

    return res;
}

double BinaryToFloatingPoint::convertToDoublePrecision() {
    const int sign = 1;
    const int expo = 11;
    const int mantis = 52;
    double res = 0;

    string exponent = _binarySequence.substr(1, expo);
    BinaryToInteger bti(16, exponent);
    int exp = bti.convertToUnsignedInteger() - 1023;
    res += pow(2, exp);
        
    string mantissa = _binarySequence.substr(12, mantis);
    for (int i = 0; i < mantis; i++) {
        if (mantissa[i] == '1') {
            res += pow(2, exp - 1 - i);
        }
    }

    if (_binarySequence[0] == '1') res = -res;

    return res;
}
