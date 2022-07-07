#pragma once

struct Vector
{
    float x,y,z;

    Vector(float px=0, float py=0, float pz=0) ;
    Vector operator+(const Vector& p);
    Vector operator-(const Vector& p);
    float operator%(const Vector& p); //dot product
    Vector operator*(const Vector& p); //cros product

};