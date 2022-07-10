#include "../include/Vector.hpp"
#include <cmath>

Vector::Vector(float px, float py, float pz) 
{
    x=px;
    y=py;
    z=pz;
}
Vector Vector::operator+( Vector p) 
{
    return Vector(x+p.x, y+p.y, z+p.z);
}
Vector Vector::operator-( Vector p) 
{
    return Vector(x-p.x, y-p.y, z-p.z);
}
Vector Vector::operator*(float k)
{
    Vector r;
    r = scale(k);
    return r;
}
float  Vector::operator%( Vector p) 
{
    return p.x*x+p.y*y+p.z*z;
}
float Vector::dot( Vector p) {
    return *this%p;
}
Vector  Vector::operator*( Vector p) 
{
    float x = y*p.z - z*p.y;
    float y = z*p.x - x*p.z;
    float z = x*p.y - y*p.x;
    return Vector(x,y,z) ;
}
Vector  Vector::cross(Vector p)
{
    float x = y*p.z - z*p.y;
    float y = z*p.x - x*p.z;
    float z = x*p.y - y*p.x;
    return Vector(x,y,z) ;
}
Vector Vector::normalize()
{
    float d = std::sqrt(x*x+y*y+z*z);
    assert( d!= 0);
    x = x/d;
    y = y/d;
    z = z/d;
    return *this;
}
Vector Vector::scale(float k) 
{
    x = x*k;
    y = y*k;
    z = z*k;
    return *this;
}