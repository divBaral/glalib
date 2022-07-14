#pragma once
#include <cmath>
#include "Vector.hpp"
struct Point
{
    float x,y,z;
    float h = 1.0f;
    Point(float px=0, float py=0, float pz=0);
    Point( Vector v );

    Point operator+(const Point& p);
    Vector operator-(const Point& p);
    void normalize();
    void homogenize();

};