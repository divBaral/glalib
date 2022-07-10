#pragma once
#include <cmath>
#include <cassert>
struct Vector
{
    float x,y,z;
    const static int h = 0;
    Vector(float px=0, float py=0, float pz=0) ;
    Vector operator+( Vector p);
    Vector operator-( Vector p);
    float operator%( Vector p); //dot product
    float dot(Vector p);

    Vector cross(Vector p);
    Vector operator*( Vector p); //cros product
    Vector normalize();
    Vector scale(float k);
    

};