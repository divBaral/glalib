#pragma once
#include <cmath>
#include <cassert>
#include <iostream>
#include "Point2d.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Vector2d.hpp"

class Matrix3f
{
public:
    Matrix3f(); //identiy Matrix3f
    Matrix3f(float a[3][3] );
    Matrix3f Invert();
    Matrix3f Pinvert();//psedo invert
    //static Matrix3f ConstructByColumns(Point2d p1, Point2d p2, Point2d p3);
    //static Matrix3f ConstructByColumns(Vector2d v1, Vector2d v2, Vector2d v3);
    template<typename T1, typename T2, typename T3>
    static Matrix3f ConstructByColumns(T1 p, T2 q, T3 r);
    Matrix3f operator*(const Matrix3f& a);
    Vector2d operator*( Vector2d v);
    Point2d operator*(Point2d p);
    Point operator*(Point p) const;
    //Vector operator*(const Vector& v);
    void Print(); //operator<<

private:
    static constexpr int m = 3;
    static constexpr int n = 3;
public:
    float mat[m][n];
};
template<typename T1, typename T2, typename T3>
Matrix3f  Matrix3f::ConstructByColumns(T1 p, T2 q, T3 r)
{
    float a[3][3];
    a[0][0]=  p.x;
    a[1][0] = p.y;
    a[2][0] = p.h;

    a[0][1]=  q.x;
    a[1][1] = q.y;
    a[2][1] = q.h;

    a[0][2]=  r.x;
    a[1][2] = r.y;
    a[2][2] = r.h;

    return Matrix3f(a);
}