#include "Vector3DPublic.h"
#include <sstream>

Vector3DPublic::Vector3DPublic() : Vector3D()
{
}

Vector3DPublic::Vector3DPublic(const double fx, const double fy, const double fz)
    : Vector3D(fx, fy, fz)
{
}

Vector3DPublic::Vector3DPublic(const Vector3D& r) : Vector3D(r)
{
}

Vector3DPublic::Vector3DPublic(const Vector3DPublic& r) : Vector3D(r)
{
}

Vector3DPublic& Vector3DPublic::operator = (const Vector3DPublic& r)
{
    Vector3D::operator = (r);
    return *this;
}

Vector3DPublic& Vector3DPublic::operator ++ ()
{
    set(getX() + 1, getY() + 1, getZ() + 1);
    return *this;
}

Vector3DPublic Vector3DPublic::operator ++ (int)
{
    Vector3DPublic old(*this);
    ++(*this);
    return old;
}

Vector3DPublic& Vector3DPublic::operator -- ()
{
    set(getX() - 1, getY() - 1, getZ() - 1);
    return *this;
}

Vector3DPublic Vector3DPublic::operator -- (int)
{
    Vector3DPublic old(*this);
    --(*this);
    return old;
}

Vector3DPublic operator + (const Vector3DPublic& l, const Vector3DPublic& r)
{
    return Vector3DPublic(l.getX() + r.getX(), l.getY() + r.getY(), l.getZ() + r.getZ());
}

Vector3DPublic operator - (const Vector3DPublic& l, const Vector3DPublic& r)
{
    return Vector3DPublic(l.getX() - r.getX(), l.getY() - r.getY(), l.getZ() - r.getZ());
}

double operator * (const Vector3DPublic& l, const Vector3DPublic& r)
{
    return l.getX() * r.getX() + l.getY() * r.getY() + l.getZ() * r.getZ();
}

Vector3DPublic::operator string() const
{
    stringstream ss;
    ss << static_cast<const Vector3D&>(*this);
    return ss.str();
}
