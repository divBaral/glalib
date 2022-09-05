#pragma once
#include <cmath>
#include <cassert>
struct Vector
{
    float x,y,z;
    int h = 0.0f;
    Vector(float px=0, float py=0, float pz=0) ;
    Vector operator+( Vector p) const;
    Vector operator+=(Vector p) ;
    Vector operator-=(const Vector& p) ;
    Vector operator-( Vector p) const;
    Vector operator*( float k) const;
    Vector operator/(float k) const;
    Vector operator-() const;
    float operator%( Vector p); //dot product
    float dot(Vector p);
    float length() const;
    Vector cross(Vector p);
    Vector operator*( Vector p) const; //cros product
    Vector normalize();
    Vector direction() const;
    Vector scale(float k);
    
    

};