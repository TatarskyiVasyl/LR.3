#pragma once
#include "Vector3D.h"

class Vector3DPrivate :
    private Vector3D
{
public:
    using Vector3D::getX;
    using Vector3D::getY;
    using Vector3D::getZ;
    using Vector3D::setX;
    using Vector3D::setY;
    using Vector3D::setZ;
    using Vector3D::set;

    Vector3DPrivate();
    Vector3DPrivate(const double fx, const double fy, const double fz);
    Vector3DPrivate(const Vector3D& r);
    Vector3DPrivate(const Vector3DPrivate& r);
    Vector3DPrivate& operator = (const Vector3DPrivate& r);

    Vector3DPrivate& operator ++ ();
    Vector3DPrivate  operator ++ (int);
    Vector3DPrivate& operator -- ();
    Vector3DPrivate  operator -- (int);

    friend Vector3DPrivate operator + (const Vector3DPrivate& l, const Vector3DPrivate& r);
    friend Vector3DPrivate operator - (const Vector3DPrivate& l, const Vector3DPrivate& r);
    friend double operator * (const Vector3DPrivate& l, const Vector3DPrivate& r);

    operator string() const;
    friend ostream& operator << (ostream& out, const Vector3DPrivate& r);
    friend istream& operator >> (istream& in, Vector3DPrivate& r);
};
