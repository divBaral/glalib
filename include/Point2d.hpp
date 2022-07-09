#pragma once
#include <cmath>
#include "Vector.hpp"
#include "Vector2d.hpp"

struct Point2d
{
    float x,y;
    const static int h = 1;//homogeneation coeffi.
    Point2d(float px=0, float py=0);
    Point2d operator+(const Point2d& p);
    Vector2d operator-(const Point2d& p);
    
    void normalize();

};