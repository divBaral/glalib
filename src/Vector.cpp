#include "../include/Vector.hpp"


Vector::Vector(float px, float py, float pz) 
{
    x=px;
    y=py;
    z=pz;
}
Vector Vector::operator+( Vector p) const
{
    return Vector(x+p.x, y+p.y, z+p.z);
}
Vector Vector::operator-( Vector p) const
{
    return Vector(x-p.x, y-p.y, z-p.z);
}
Vector Vector::operator*(float k) const
{
    return Vector(x*k, y*k, z*k);
}
float  Vector::operator%( Vector p) 
{
    return p.x*x+p.y*y+p.z*z;
}
float Vector::dot( Vector p) {
    return *this%p;
}
Vector Vector::operator*( Vector p) const
{ 
    Vector r;
     r.x = y*p.z - z*p.y;
     r.y = z*p.x - x*p.z;
     r.z = x*p.y - y*p.x;
    return r;
}
Vector  Vector::cross(Vector p)
{
    Vector r;
     r.x = y*p.z - z*p.y;
     r.y = z*p.x - x*p.z;
     r.z = x*p.y - y*p.x;
    return r;
}
Vector Vector::normalize()
{
    float d = std::sqrt(x*x+y*y+z*z);
    if ( d == 0 ) return Vector(0,0,0);
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
    return Vector(x,y,z);
}
float Vector::length() const
{
    return sqrt(x*x+ y*y+ z*z);
}
Vector Vector::direction()  const
{
    float d = this->length();
    Vector r(0,0,0);
    if ( d != 0 ) r = Vector(x/d, y/d, z/d);
    return r;
}
Vector Vector::operator/(float k) const
{
    return Vector(x/k,y/k,z/k);

}
Vector Vector::operator-() const 
{ 
    return Vector(-x, -y, -z);
}
Vector Vector::operator+=(Vector p) 
{
    x+=p.x;
    z+=p.z;
    y+=p.y;
    return *this;
}
Vector Vector::operator-=(const Vector& p) 
{
    x-=p.x;
    z-=p.z;
    y-=p.y;
    return *this;
}