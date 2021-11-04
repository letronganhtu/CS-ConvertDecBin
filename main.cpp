#include <string>
#include <iomanip>

#include "BinToDec.h"
#include "ConsolePresentation.h"
#include "DecToBin.h"

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (int i = 0; i < a.size(); ++i)
        out << a[i];
    return out;
}

int main() {
    int choice = 0;
    bool firstTime = true;
    cout << "WELCOME TO BINARY CONVERT\n\nChoose what you want to do\n";
    cout << "1. Decimal convert to Binary\n2. Binary convert to Decimal\n3. Exit program\n\n";
    cout << "Enter your choice (1/2/3): ";
    while (choice != 1 && choice != 2 && choice != 3) {
        cin >> choice;
        firstTime = false;
        if (choice != 1 && choice != 2 && choice != 3 && !firstTime) {
            system("cls");
            cout << "WELCOME TO BINARY CONVERT\n\nChoose what you want to do\n";
            cout << "1. Decimal convert to Binary\n2. Binary convert to Decimal\n3. Exit program\n\n";
            cout << "Wrong choice. Let's try again\n";
            cout << "Enter your choice (1/2/3): ";
        }
    }
    if (choice == 3) cout << "\nGood Bye ^^";
    else if (choice == 1) {
        system("cls");
        cout << "WELCOME TO BINARY CONVERT\n\n1. Decimal convert to Binary\n";
        cout << "Let's enter your value: ";
        double x;
        cin >> x;
        cout << "\nSingle precision floating-point: " << Presentation::representOutputBitSequence(DoubleToBin::to32Bit(x));
        cout << "\n\nDouble precision floating-point: " << Presentation::representOutputBitSequence(DoubleToBin::to64Bit(x));
        cout << "\n\nUnsigned interger 8 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to8Bit(x));
        cout << "\n\nInterger 8 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to2s8Bit(x));
        cout << "\n\nUnsigned interger 16 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to16Bit(x));
        cout << "\n\nInterger 16 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to2s16Bit(x));
        cout << "\n\nUnsigned interger 32 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to32Bit(x));
        cout << "\n\nInterger 32 bits: " << Presentation::representOutputBitSequence(IntegerToBin::to2s32Bit(x));
    }
    else {
        system("cls");
        cout << "WELCOME TO BINARY CONVERT\n\n2. Binary convert to Decimal\n";
        cout << "Let's choose your length of binary sequence (8/16/32/64)\n";
        cout << "Your choice: ";
        int choice1;
        cin >> choice1;
        cout << "Enter your binary sequence: ";
        string bin;
        cin >> bin;
        CheckBinarySequence check;
        while (!check.isValid(bin)) {
            system("cls");
            cout << "WELCOME TO BINARY CONVERT\n\n2. Binary convert to Decimal\n\n";
            cout << "Wrong input. Please type again!\n";
            cout << "Let's enter your binary sequence: ";
            cin >> bin;
        }

    }
    /*string binarySequence;
    cin >> binarySequence;*/
    /*BinaryToInteger bti(8, binarySequence);
    cout << InputRepresentation::represent(bti.numberOfBit(), bti.binarySequence()) << endl;
    cout << bti.convertToUnsignedInteger() << endl;
    cout << bti.convertToSignedInteger();
    BinaryToFloatingPoint btf(64, binarySequence);
    cout << btf.convertToDoublePrecision();*/

    return 0;
}
// g++ BinToDec.cpp BinToDec.h ConsolePresentation.cpp ConsolePresentation.h DecToBin.cpp DecToBin.h main.cpp