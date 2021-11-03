#include <sstream>

#include "ConsolePresentation.h"

string InputPresentation::representInputBitSequence(int numBit, string bin) {
    stringstream out;
    out << "Your input binary sequence in " << numBit << " bit is: ";

    for (int i = 0; i < numBit; i++) {
        if (i != numBit - 1 && i % 4 == 3) out << bin[i] << "'";
        else out << bin[i];
    }

    string result = out.str();
    return result;
}