#include "include/Vector.hpp"

Vector::Vector(float px, float py, float pz) 
{
    x=px;
    y=py;
    z=pz;
}
Vector Vector::operator+(const Vector &p) 
{
    return Vector(x+p.x, y+p.y, z+p.z);
}
Vector Vector::operator-(const Vector &p) 
{
    return Vector(x-p.x, y-p.y, z-p.z);
}
float  Vector::operator%(const Vector &p) 
{
    return p.x*x+p.y*y+p.z*z;
}
Vector  Vector::operator*(const Vector &p) 
{
    float x = y*p.z - z*p.y;
    float y = z*p.x - x*p.z;
    float z = x*p.y - y*p.x;
    return Vector(x,y,z) ;
}