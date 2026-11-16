#include "Triad.h"
#include <cmath>
#include <cstdlib>
#include <stdexcept>

void Triad::error(const char* msg)
{
#ifdef UNIT_TEST
    throw invalid_argument(msg);
#else
    cout << "Помилка: " << msg << endl;
    exit(1);
#endif
}

bool Triad::valid(const double value)
{
    return std::isfinite(value);
}

Triad::Triad() : first(0), second(0), third(0)
{
}

Triad::Triad(const double f, const double s, const double t) : first(0), second(0), third(0)
{
    set(f, s, t);
}

Triad::Triad(const Triad& r) : first(r.first), second(r.second), third(r.third)
{
}

void Triad::setFirst(const double value)
{
    if (!valid(value))
        error("перше число має бути скінченним");
    first = value;
}

void Triad::setSecond(const double value)
{
    if (!valid(value))
        error("друге число має бути скінченним");
    second = value;
}

void Triad::setThird(const double value)
{
    if (!valid(value))
        error("третє число має бути скінченним");
    third = value;
}

void Triad::set(const double f, const double s, const double t)
{
    if (!valid(f))
        error("перше число має бути скінченним");
    if (!valid(s))
        error("друге число має бути скінченним");
    if (!valid(t))
        error("третє число має бути скінченним");
    first = f;
    second = s;
    third = t;
}

bool operator > (const Triad& l, const Triad& r)
{
    return l.first > r.first
        || (l.first == r.first && l.second > r.second)
        || (l.first == r.first && l.second == r.second && l.third > r.third);
}

bool operator == (const Triad& l, const Triad& r)
{
    return l.first == r.first && l.second == r.second && l.third == r.third;
}

bool operator <  (const Triad& l, const Triad& r) { return r > l; }
bool operator != (const Triad& l, const Triad& r) { return !(l == r); }
bool operator >= (const Triad& l, const Triad& r) { return l > r || l == r; }
bool operator <= (const Triad& l, const Triad& r) { return l < r || l == r; }

ostream& operator << (ostream& out, const Triad& r)
{
    return out << "( " << r.first << ", " << r.second << ", " << r.third << " )";
}

istream& operator >> (istream& in, Triad& r)
{
    double f, s, t;
    cout << "first  = "; in >> f;
    cout << "second = "; in >> s;
    cout << "third  = "; in >> t;
    if (in.fail())
        Triad::error("введено не число");
    r.set(f, s, t);
    return in;
}

Triad makeTriad(const double f, const double s, const double t)
{
    return Triad(f, s, t);
}
