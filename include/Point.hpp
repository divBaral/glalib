#pragma once
#include <cmath>
struct Point 
{
    float x,y,z;
    Point(float px=0, float py=0, float pz=0) ;
    Point operator+(const Point& p);
    Point operator-(const Point& p);
    void normalize();

};