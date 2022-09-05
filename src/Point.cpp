#include "../include/Point.hpp"

Point::Point(float px, float py, float pz) 
{
    x=px;
    y=py;
    z=pz;
}
Point Point::operator/(float k) const 
{
    return Point(x/k, y/k, z/k);
}
Point Point::operator*(float k) const 
{
    return Point(x*k, y*k, z*k);
}
Point Point::operator+(const Point &p) 
{
    return Point(x+p.x, y+p.y, z+p.z);
}
Point::operator Vector() const {
    return Vector(x,y,z);
}
Vector Point::operator-(const Point &p) const
{
    return Vector(x-p.x, y-p.y, z-p.z);
}
Point Point::operator-()
{
    return Point(-x,-y,-z);
}
void Point::normalize() 
{
    float d = std::sqrt(x*x+y*y+z*z);
    x = x/d;
    y = y/d;
    z = z/d;
   
}
float Point::length() const 
{
    return sqrt(x*x+y*y+z*z);
}
Point Point::operator+=(const Point& p)
{
    x+=p.x;
    z+=p.z;
    y+=p.y;
    return *this;
}
Point Point::operator-=(const Point& p)
{
    x-=p.x;
    z-=p.z;
    y-=p.y;
    return *this;
}
void Point::homogenize()
{
  
    if ( h !=0 ) {
        x = x/h;
        y = y/h;
        z = z/h;
    }
}

Point::Point( Vector v ) {
    x = v.x;
    y = v.y;
    z = v.z;
}
Vector Point::direction()  const
{
    float d = this->length();
    Vector r(0,0,0);
    if ( d != 0 ) r = Vector(x/d, y/d, z/d);
    return r;
}