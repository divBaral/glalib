#include "../include/Vector2d.hpp"

Vector2d::Vector2d(float px, float py) 
{
    x=px;
    y=py;
   
}
Vector2d Vector2d::operator+(const Vector2d &p) 
{
    return Vector2d(x+p.x, y+p.y);
}
Vector2d Vector2d::operator-(const Vector2d &p) 
{
    return Vector2d(x-p.x, y-p.y);
}
float  Vector2d::operator%(const Vector2d &p) 
{
    return p.x*x+p.y*y;
}
float  Vector2d::operator*(const Vector2d &p) 
{
    return (x*p.y-y*p.x);
}