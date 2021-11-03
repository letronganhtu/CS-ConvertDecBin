#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a);

template<class T>
vector<T> operator~(const vector<T>& a);

template<class T>
vector<T>& operator++(vector<T>& a, int );

template<class T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b);

class Math {
public:
    static unsigned long long mpow(unsigned long long x, int y);
};

class IntegerToBin {
public:
    static vector<int> toBit(const long long &d);

    static vector<int> to64Bit(const long long &d);

    static vector<int> to8Bit(const long long &d);

    static vector<int> to11Bit(const long long &d);

    static vector<int> to16Bit(const long long &d);

    static vector<int> to32Bit(const long long &d);

    static vector<int> to2s8Bit(const long long &d);

    static vector<int> to2s16Bit(const long long &d);

    static vector<int> to2s32Bit(const long long &d);
};

class DoubleToBin {
public:
    static vector<int> to32Bit(const double& b);

    static vector<int> to64Bit(const double& b);
};