#pragma once
#include <cmath>
#include <cassert>
#include <iostream>
#include "Point.hpp"
#include "Vector.hpp"
#include "Vector.hpp"
#include "AffineTransformation2.hpp"


class Matrix4f
{
public:
    Matrix4f(); //identiy Matrix4f
   // Matrix4f(Matrix4f&& m) noexcept;
    Matrix4f(float a[4][4] );
    Matrix4f(const Matrix3f& m );
    Matrix4f(float a11, float a12, float a13, float a14,
             float a21, float a22, float a23, float a24, 
             float a31, float a32, float a33, float a34,
             float a41, float a42, float a43, float a44 );

    Matrix4f Invert();
    Matrix4f Pinvert();//psedo invert
    template<typename T1, typename T2, typename T3, typename T4>
    static Matrix4f ConstructByColumns(T1 p, T2 q, T3 r, T4 s);
    Matrix4f operator*(const Matrix4f& a);
    Vector operator*( Vector v) const;
    Point operator*(Point p) const;
    //Vector operator*(const Vector& v);
    void Print(); //operator<<


private:
    static constexpr int m = 4;
    static constexpr int n = 4;
public:
    float mat[m][n];
};
template<typename T1, typename T2, typename T3, typename T4>
Matrix4f  Matrix4f::ConstructByColumns(T1 p, T2 q, T3 r, T4 s)
{
    float a[4][4];
    a[0][0]=  p.x;
    a[1][0] = p.y;
    a[2][0] = p.z;
    a[3][0] = p.h;

    a[0][1]=  q.x;
    a[1][1] = q.y;
    a[2][1] = q.z;
    a[3][1] = q.h;

    a[0][2]=  r.x;
    a[1][2] = r.y;
    a[2][2] = r.z;
    a[3][2] = r.h;

    a[0][3]=  s.x;
    a[1][3] = s.y;
    a[2][3] = s.z;
    a[3][3] = s.h;

    return Matrix4f(a);
}