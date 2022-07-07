#pragma once
#include <cmath>
#include <cassert>
#include <iostream>
#include "Vector.hpp"
#include "Vector2d.hpp"

class Matrix3f
{
public:
    Matrix3f(); //identiy Matrix3f
    Matrix3f(float a[3][3] );
    Matrix3f invert();
    Matrix3f pinvert();//psedo invert
    Matrix3f operator*(const Matrix3f& a);
    Vector2d operator*(const Vector2d& v);
    Vector operator*(const Vector& v);
    void print();

private:
    static constexpr int m = 3;
    static constexpr int n = 3;
    float mat[m][n];
};