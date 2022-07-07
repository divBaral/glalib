#pragma once
#include <cmath>
struct Point2d
{
    float x,y;

    Point2d(float px=0, float py=0) ;
    Point2d operator+(const Point2d& p);
    Point2d operator-(const Point2d& p);
    void normalize();

};