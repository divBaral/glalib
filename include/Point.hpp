#pragma once
#include <cmath>
#include "Vector.hpp"
struct Point
{
    float x,y,z;
    static const int h = 1;
    Point(float px=0, float py=0, float pz=0);
    Point( Vector v );
    Point operator+(const Point& p);
    Vector operator-(const Point& p);
    void normalize();

};