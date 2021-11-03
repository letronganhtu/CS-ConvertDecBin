#include <string>
#include <iomanip>

#include "BinToDec.h"
#include "ConsolePresentation.h"
#include "DecToBin.h"

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

    }
    else {

    }
    /*string binarySequence;
    cin >> binarySequence;*/
    /*BinaryToInteger bti(8, binarySequence);
    cout << InputRepresentation::represent(bti.numberOfBit(), bti.binarySequence()) << endl;
    cout << bti.convertToUnsignedInteger() << endl;
    cout << bti.convertToSignedInteger();
    BinaryToFloatingPoint btf(64, binarySequence);
    cout << btf.convertToDoublePrecision();

    double x;
    cin >> x;

    bitset<64> b(x);
    cout << b.to_string() << '\n';

    cout << DoubleToBin::to32Bit(x);
    cout << '\n' << DoubleToBin::to64Bit(x);*/

    return 0;
}
// g++ BinToDec.cpp BinToDec.h ConsolePresentation.cpp ConsolePresentation.h DecToBin.cpp DecToBin.h main.cpp