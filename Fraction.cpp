#include "Fraction.h"
#include <sstream>
#include <cstdlib>

void Fraction::error(const char* msg)
{
#ifdef UNIT_TEST
    throw invalid_argument(msg);
#else
    cout << "Помилка: " << msg << endl;
    exit(1);
#endif
}

Fraction::Fraction(const int i, const int f)
{
    set(i, f);
}

Fraction::Fraction(const Fraction& r) : Pair(r)
{
}

Fraction::Fraction(const Pair& r)
{
    set(r.getFirst(), r.getSecond());
}

Fraction::~Fraction(void)
{
}

void Fraction::setInt(const int value)
{
    if (value < 0)
        error("ціла частина не може бути від'ємною");
    Pair::setFirst(value);
}

void Fraction::setFrac(const int value)
{
    if (value < 0)
        error("дробова частина не може бути від'ємною");
    Pair::setSecond(value);
}

void Fraction::set(const int i, const int f)
{
    setInt(i);
    setFrac(f);
}

int Fraction::cmpFrac(const int a, const int b)
{
    string sa = to_string(a), sb = to_string(b);
    while (sa.size() < sb.size()) sa += '0';
    while (sb.size() < sa.size()) sb += '0';
    if (sa == sb) return 0;
    return sa > sb ? 1 : -1;
}

int Fraction::cmp(const Fraction& l, const Fraction& r)
{
    if (l.getInt() != r.getInt())
        return l.getInt() > r.getInt() ? 1 : -1;
    return cmpFrac(l.getFrac(), r.getFrac());
}

bool operator == (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) == 0; }
bool operator != (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) != 0; }
bool operator >  (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) > 0; }
bool operator <  (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) < 0; }
bool operator >= (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) >= 0; }
bool operator <= (const Fraction& l, const Fraction& r) { return Fraction::cmp(l, r) <= 0; }

Fraction::operator string() const
{
    stringstream ss;
    ss << getInt() << "." << getFrac();
    return ss.str();
}

ostream& operator << (ostream& out, const Fraction& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Fraction& r)
{
    int i, f;
    cout << "ціла частина     = "; in >> i;
    cout << "дробова частина  = "; in >> f;
    r.set(i, f);
    return in;
}
