#include "Vector3D.h"
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

void Vector3D::error(const char* msg)
{
#ifdef UNIT_TEST
    throw invalid_argument(msg);
#else
    cout << "Помилка: " << msg << endl;
    exit(1);
#endif
}

bool Vector3D::valid(const double value)
{
    return std::isfinite(value);
}

Vector3D::Vector3D() : Object(), x(0), y(0), z(0)
{
}

Vector3D::Vector3D(const double fx, const double fy, const double fz)
    : Object(), x(0), y(0), z(0)
{
    set(fx, fy, fz);
}

Vector3D::Vector3D(const Vector3D& r) : Object(r), x(r.x), y(r.y), z(r.z)
{
}

Vector3D& Vector3D::operator = (const Vector3D& r)
{
    Object::operator = (r);
    x = r.x;
    y = r.y;
    z = r.z;
    return *this;
}

void Vector3D::setX(const double value)
{
    if (!valid(value))
        error("координата x має бути скінченним числом");
    x = value;
}

void Vector3D::setY(const double value)
{
    if (!valid(value))
        error("координата y має бути скінченним числом");
    y = value;
}

void Vector3D::setZ(const double value)
{
    if (!valid(value))
        error("координата z має бути скінченним числом");
    z = value;
}

void Vector3D::set(const double fx, const double fy, const double fz)
{
    if (!valid(fx))
        error("координата x має бути скінченним числом");
    if (!valid(fy))
        error("координата y має бути скінченним числом");
    if (!valid(fz))
        error("координата z має бути скінченним числом");
    x = fx;
    y = fy;
    z = fz;
}

Vector3D& Vector3D::operator ++ ()
{
    set(x + 1, y + 1, z + 1);
    return *this;
}

Vector3D Vector3D::operator ++ (int)
{
    Vector3D old(*this);
    ++(*this);
    return old;
}

Vector3D& Vector3D::operator -- ()
{
    set(x - 1, y - 1, z - 1);
    return *this;
}

Vector3D Vector3D::operator -- (int)
{
    Vector3D old(*this);
    --(*this);
    return old;
}

Vector3D operator + (const Vector3D& l, const Vector3D& r)
{
    return Vector3D(l.x + r.x, l.y + r.y, l.z + r.z);
}

Vector3D operator - (const Vector3D& l, const Vector3D& r)
{
    return Vector3D(l.x - r.x, l.y - r.y, l.z - r.z);
}

double operator * (const Vector3D& l, const Vector3D& r)
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}

Vector3D::operator string() const
{
    stringstream ss;
    ss << *this;
    return ss.str();
}

ostream& operator << (ostream& out, const Vector3D& r)
{
    return out << "( " << r.x << ", " << r.y << ", " << r.z << " )";
}

istream& operator >> (istream& in, Vector3D& r)
{
    double fx, fy, fz;
    cout << "x = "; in >> fx;
    cout << "y = "; in >> fy;
    cout << "z = "; in >> fz;
    if (in.fail())
        Vector3D::error("введено не число");
    r.set(fx, fy, fz);
    return in;
}
