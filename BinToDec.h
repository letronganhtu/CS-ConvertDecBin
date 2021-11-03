#include <iostream>
using namespace std;

// Check if the input string is a format of binary sequence or not
class CheckBinarySequence {
public:
    bool isValid(string);
};

// Convert from Binary to Integer 8/16/32 bits in Decimal (include Unsigned and Signed)
class BinaryToInteger {
private:
    int _numberOfBit; // Number of bits in string, it can be 8, 16 or 32 depend on user
    string _binarySequence; // Represent bit sequence in a string
public:
    // Require user must initialize 2 value as parameter above in constructor
    BinaryToInteger(int , string);
public:
    // Get value of 2 private members without changing them by using const
    int numberOfBit() const;
    string binarySequence() const;
public:
    // 2 function to convert bit sequence to integer number
    unsigned int convertToUnsignedInteger();
    int convertToSignedInteger();
};

// Convert from Binary to Floating-Point 32/64 bits
class BinaryToFloatingPoint {
private:
    int _numberOfBit; // Number of bits in string, it can be 32 or 64 bits depend on user
    string _binarySequence; // Represent bit sequence in a string
public:
    BinaryToFloatingPoint(int, string);
public:
    // Get value of 2 private members without changing them by using const
    int numberOfBit() const;
    string binarySequence() const;
public:
    // Sign: 1, Exponent: 8, Mantissa: 23
    float convertToSinglePrecisionFloat(); 
    // Sign: 1, Exponent: 11, Mantissa: 52
    double convertToDoublePrecision();
};