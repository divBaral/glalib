#pragma once
#include <cmath>
#include "Vector.hpp"
struct Point
{
    float x,y,z;
    float h = 1.0f;
    Point(float px=0, float py=0, float pz=0);
    Point( Vector v );
    operator Vector() const;

    Point operator+(const Point& p);
    Point operator+=(const Point& p);
    Vector operator-(const Point& p) const;
    Point operator-();
    Point operator/(float k) const;
    Point operator*(float k) const;
    Vector direction() const;
    void normalize();
    void homogenize();
    float length() const;

};