#pragma once
#include "Vector3D.h"

class Vector3DPublic :
    public Vector3D
{
public:
    Vector3DPublic();
    Vector3DPublic(const double fx, const double fy, const double fz);
    Vector3DPublic(const Vector3D& r);
    Vector3DPublic(const Vector3DPublic& r);
    Vector3DPublic& operator = (const Vector3DPublic& r);

    Vector3DPublic& operator ++ ();
    Vector3DPublic  operator ++ (int);
    Vector3DPublic& operator -- ();
    Vector3DPublic  operator -- (int);

    friend Vector3DPublic operator + (const Vector3DPublic& l, const Vector3DPublic& r);
    friend Vector3DPublic operator - (const Vector3DPublic& l, const Vector3DPublic& r);
    friend double operator * (const Vector3DPublic& l, const Vector3DPublic& r);

    operator string() const;
};
