#include <vector>

#include "DecToBin.h"

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (int i = 0; i < a.size(); ++i)
        out << a[i];
    return out;
}

template<class T>
vector<T> operator~(const vector<T>& a) {
    vector<T> out(a.size());
    for (int i = 0; i < a.size(); ++i)
        out[i] = a[i] ^ 1;
    return out;
}

template<class T>
vector<T>& operator++(vector<T>& a, int) {
    int r = 0;
    a[a.size() - 1] ++;
    r = a.back() / 2;
    a[a.size() - 1] %= 2;
    for (int i = a.size() - 2; i >= 0; --i) {
        a[i] += r;
        r = a[i] / 2;
        a[i] %= 2;
    }
    return a;
}

template<class T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
    for (int i = 0; i < b.size(); ++i)
        a.push_back(b[i]);

    return a;
}

unsigned long long Math::mpow(unsigned long long x, int y) {
    unsigned long long res = 1;
    while(y) {
        if (y & 1)
            res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

vector<int> IntegerToBin::toBit(const long long &d) {
    vector<int> res;
    res.clear();
       
    long long _d = abs(d);
    for(; _d; _d >>= 1)
        res.push_back((_d & 1 ? 1 : 0));

    reverse(res.begin(), res.end());

    return res;
}

vector<int> IntegerToBin::to64Bit(const long long &d) {
    vector<int> res;
    res.clear();
    long long _d = abs(d);
    for (; _d; _d >>= 1) {
        res.push_back((_d & 1 ? 1 : 0));
    }
    for (int i = res.size(); i <= 63; ++i)
        res.push_back(0);

    reverse(res.begin(), res.end());
    return res;
}

vector<int> IntegerToBin::to8Bit(const long long &d) {
    vector<int> res = to64Bit(d);
            
    return vector<int>(res.begin() + 64 - 8, res.end());
}

vector<int> IntegerToBin::to11Bit(const long long &d) {
    vector<int> res = to64Bit(d);

    return vector<int>(res.begin() + 64 - 11, res.end());
}

vector<int> IntegerToBin::to16Bit(const long long &d) {
    vector<int> res = to64Bit(d);

    return vector<int>(res.begin() + 64 - 16, res.end());
}

vector<int> IntegerToBin::to32Bit(const long long &d) {
    vector<int> res = to64Bit(d);

    return vector<int>(res.begin() + 64 - 32, res.end());
}

vector<int> IntegerToBin::to2s8Bit(const long long &d) {
    vector<int> a = to8Bit(d);
    if (d < 0) {
        a = ~a;
        a++;
    }
    if ((long long)(1 << 8) - 1 <= abs(d))
        throw runtime_error("over size of 8bits");
            
    return a;
}

vector<int> IntegerToBin::to2s16Bit(const long long &d) {
    vector<int> a = to16Bit(d);
    if (d < 0) {
        a = ~a;
        a++;
    }
    if ((long long)(1 << 16) - 1 <= abs(d))
        throw runtime_error("over size of 16bits");
            
    return a;
}

vector<int> IntegerToBin::to2s32Bit(const long long &d) {
    vector<int> a = to32Bit(d);
    if (d < 0) {
        a = ~a;
        a++;
    }
    if ((long long)(1ULL << 32) - 1 <= abs(d))//Warning: (1 << 32) overflow
        throw runtime_error("over size of 32bits");

    return a;
}

vector<int> DoubleToBin::to32Bit(const double& b) {
    long long _b = (long long)b;
    vector<int> getBit = IntegerToBin::toBit(_b); 
    int need = 24 - getBit.size();
    _b =(long long) (b * Math::mpow(2, need));
    vector<int> man = IntegerToBin::toBit(_b);
    int e = 127 + 23 - need; 
    vector<int> res;
    res.push_back(b < 0 ? 1 : 0);
    res += IntegerToBin::to8Bit(e);
    res += vector<int>(man.begin() + 1, man.end());

    return res;
}

vector<int> DoubleToBin::to64Bit(const double& b) {
    unsigned long long _b = (unsigned long long)b;
    vector<int> getBit = IntegerToBin::toBit(_b); 
    int need = 53 - getBit.size();
    _b = (unsigned long long)(b * Math::mpow(2, need));
    vector<int> man = IntegerToBin::toBit(_b);
    int e = 1023 + 52 - need;
    vector<int> res;
    res.push_back(b < 0 ? 1 : 0);
    res += IntegerToBin::to11Bit(e);
    res += vector<int>(man.begin() + 1, man.end());

    return res;
}
