#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair
{
    int first, second;
public:
    Pair(const int f = 0, const int s = 0);
    Pair(const Pair& r);
    Pair& operator = (const Pair& r) = default;
    ~Pair(void);

    int getFirst() const { return first; }
    int getSecond() const { return second; }

    void setFirst(const int value) { first = value; }
    void setSecond(const int value) { second = value; }
    void set(const int f, const int s) { setFirst(f); setSecond(s); }

    friend bool operator >  (const Pair& l, const Pair& r);
    friend bool operator <  (const Pair& l, const Pair& r);
    friend bool operator == (const Pair& l, const Pair& r);
    friend bool operator != (const Pair& l, const Pair& r);
    friend bool operator >= (const Pair& l, const Pair& r);
    friend bool operator <= (const Pair& l, const Pair& r);

    operator string() const;
    friend ostream& operator << (ostream& out, const Pair& r);
    friend istream& operator >> (istream& in, Pair& r);
};
