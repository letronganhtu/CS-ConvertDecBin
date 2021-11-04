#include <sstream>

#include "ConsolePresentation.h"

string Presentation::representInputBitSequence(int numBit, string bin) {
    stringstream out;
    out << "Your input binary sequence in " << numBit << " bit is: ";

    for (int i = 0; i < numBit; i++) {
        if (i != numBit - 1 && i % 4 == 3) out << bin[i] << "'";
        else out << bin[i];
    }

    string result = out.str();
    return result;
}

string Presentation::representOutputBitSequence(vector<int> bin) {
    stringstream out;

    for (int i = 0; i < bin.size(); i++) {
        if (i != bin.size() - 1 && i % 4 == 3) out << bin[i] << "'";
        else out << bin[i];
    }

    string result = out.str();
    return result;
}