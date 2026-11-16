#pragma once
#include <iostream>
#include <string>

using namespace std;

class Triad
{
    double first, second, third;
    static bool valid(const double value);

protected:
    static void error(const char* msg);

public:
    Triad();
    Triad(const double f, const double s, const double t);
    Triad(const Triad& r);
    Triad& operator = (const Triad& r) = default;

    double getFirst() const { return first; }
    double getSecond() const { return second; }
    double getThird() const { return third; }

    void setFirst(const double value);
    void setSecond(const double value);
    void setThird(const double value);
    void set(const double f, const double s, const double t);

    friend bool operator >  (const Triad& l, const Triad& r);
    friend bool operator <  (const Triad& l, const Triad& r);
    friend bool operator == (const Triad& l, const Triad& r);
    friend bool operator != (const Triad& l, const Triad& r);
    friend bool operator >= (const Triad& l, const Triad& r);
    friend bool operator <= (const Triad& l, const Triad& r);

    friend ostream& operator << (ostream& out, const Triad& r);
    friend istream& operator >> (istream& in, Triad& r);
};

Triad makeTriad(const double f, const double s, const double t);
