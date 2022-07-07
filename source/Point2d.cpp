#include "include/Point2d.hpp"
#include <cmath>

Point2d::Point2d(float px, float py) 
{
    x=px;
    y=py;
    
}
Point2d Point2d::operator+(const Point2d &p) 
{
    return Point2d(x+p.x, y+p.y);
}
Point2d Point2d::operator-(const Point2d &p) 
{
    return Point2d(x-p.x, y-p.y);
}
void Point2d::normalize() 
{
    float d = std::sqrt(x*x+y*y);
    x = x/d;
    y = y/d;
   
}