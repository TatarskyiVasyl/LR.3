#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Vector3D :
    public Object
{
    double x, y, z;
    static bool valid(const double value);
    static void error(const char* msg);

public:
    Vector3D();
    Vector3D(const double fx, const double fy, const double fz);
    Vector3D(const Vector3D& r);
    Vector3D& operator = (const Vector3D& r);

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(const double value);
    void setY(const double value);
    void setZ(const double value);
    void set(const double fx, const double fy, const double fz);

    Vector3D& operator ++ ();
    Vector3D  operator ++ (int);
    Vector3D& operator -- ();
    Vector3D  operator -- (int);

    friend Vector3D operator + (const Vector3D& l, const Vector3D& r);
    friend Vector3D operator - (const Vector3D& l, const Vector3D& r);
    friend double operator * (const Vector3D& l, const Vector3D& r);

    operator string() const;
    friend ostream& operator << (ostream& out, const Vector3D& r);
    friend istream& operator >> (istream& in, Vector3D& r);
};
