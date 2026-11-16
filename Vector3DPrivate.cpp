#include "Vector3DPrivate.h"
#include <sstream>

Vector3DPrivate::Vector3DPrivate() : Vector3D()
{
}

Vector3DPrivate::Vector3DPrivate(const double fx, const double fy, const double fz)
    : Vector3D(fx, fy, fz)
{
}

Vector3DPrivate::Vector3DPrivate(const Vector3D& r) : Vector3D(r)
{
}

Vector3DPrivate::Vector3DPrivate(const Vector3DPrivate& r) : Vector3D(r)
{
}

Vector3DPrivate& Vector3DPrivate::operator = (const Vector3DPrivate& r)
{
    Vector3D::operator = (r);
    return *this;
}

Vector3DPrivate& Vector3DPrivate::operator ++ ()
{
    set(getX() + 1, getY() + 1, getZ() + 1);
    return *this;
}

Vector3DPrivate Vector3DPrivate::operator ++ (int)
{
    Vector3DPrivate old(*this);
    ++(*this);
    return old;
}

Vector3DPrivate& Vector3DPrivate::operator -- ()
{
    set(getX() - 1, getY() - 1, getZ() - 1);
    return *this;
}

Vector3DPrivate Vector3DPrivate::operator -- (int)
{
    Vector3DPrivate old(*this);
    --(*this);
    return old;
}

Vector3DPrivate operator + (const Vector3DPrivate& l, const Vector3DPrivate& r)
{
    return Vector3DPrivate(l.getX() + r.getX(), l.getY() + r.getY(), l.getZ() + r.getZ());
}

Vector3DPrivate operator - (const Vector3DPrivate& l, const Vector3DPrivate& r)
{
    return Vector3DPrivate(l.getX() - r.getX(), l.getY() - r.getY(), l.getZ() - r.getZ());
}

double operator * (const Vector3DPrivate& l, const Vector3DPrivate& r)
{
    return l.getX() * r.getX() + l.getY() * r.getY() + l.getZ() * r.getZ();
}

Vector3DPrivate::operator string() const
{
    stringstream ss;
    ss << *this;
    return ss.str();
}

ostream& operator << (ostream& out, const Vector3DPrivate& r)
{
    return out << static_cast<const Vector3D&>(r);
}

istream& operator >> (istream& in, Vector3DPrivate& r)
{
    return in >> static_cast<Vector3D&>(r);
}
