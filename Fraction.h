#pragma once
#include "Pair.h"

class Fraction :
    public Pair
{
    static void error(const char* msg);
    static int cmpFrac(const int a, const int b);
    static int cmp(const Fraction& l, const Fraction& r);
public:
    Fraction(const int i = 0, const int f = 0);
    Fraction(const Fraction& r);
    Fraction& operator = (const Fraction& r) = default;
    Fraction(const Pair& r);
    ~Fraction(void);

    int getInt() const { return getFirst(); }
    int getFrac() const { return getSecond(); }

    void setInt(const int value);
    void setFrac(const int value);
    void set(const int i, const int f);

    void setFirst(const int value) { setInt(value); }
    void setSecond(const int value) { setFrac(value); }

    friend bool operator == (const Fraction& l, const Fraction& r);
    friend bool operator != (const Fraction& l, const Fraction& r);
    friend bool operator >  (const Fraction& l, const Fraction& r);
    friend bool operator <  (const Fraction& l, const Fraction& r);
    friend bool operator >= (const Fraction& l, const Fraction& r);
    friend bool operator <= (const Fraction& l, const Fraction& r);

    operator string() const;
    friend ostream& operator << (ostream& out, const Fraction& r);
    friend istream& operator >> (istream& in, Fraction& r);
};
