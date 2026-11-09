#include "Pair.h"
#include <sstream>

Pair::Pair(const int f, const int s)
{
    setFirst(f);
    setSecond(s);
}

Pair::Pair(const Pair& r)
{
    first = r.first;
    second = r.second;
}

Pair::~Pair(void)
{
}

bool operator > (const Pair& l, const Pair& r)
{
    return l.first > r.first
        || (l.first == r.first && l.second > r.second);
}

bool operator == (const Pair& l, const Pair& r)
{
    return l.first == r.first && l.second == r.second;
}

bool operator <  (const Pair& l, const Pair& r) { return r > l; }
bool operator != (const Pair& l, const Pair& r) { return !(l == r); }
bool operator >= (const Pair& l, const Pair& r) { return l > r || l == r; }
bool operator <= (const Pair& l, const Pair& r) { return l < r || l == r; }

Pair::operator string() const
{
    stringstream ss;
    ss << "( " << getFirst() << ", " << getSecond() << " )";
    return ss.str();
}

ostream& operator << (ostream& out, const Pair& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Pair& r)
{
    int f, s;
    cout << "first  = "; in >> f;
    cout << "second = "; in >> s;
    r.set(f, s);
    return in;
}
