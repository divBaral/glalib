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

Vector2d Vector2d::max(Vector2d v){
    float a,b;
    if(y<=v.y){
        b = v.y;
    }else{b = y;}
    if(x<=v.x){
        a = v.x;
    }else{a = x;}

    return Vector2d(a,b);
}

Vector2d Vector2d::min(Vector2d v){
    
    float a,b;
    if(y>=v.y){
        b = v.y;
    }else{b = y;}
    if(x>=v.x){
        a = v.x;
    }else{a = x;}

    return Vector2d(a,b);

}
float Vector2d::dot(const Vector2d& v) 
{
    return x*v.x+y*v.y;
}
float Vector2d::length() const
{
    return sqrt(x*x+y*y);
}
// Vector2d Vector2d::Vector2d(const Point2d& p)
// {
//     return Vector2d(p.x, p.y);
// }