
#pragma once
#include <cmath>

struct Vector2d
{
    float x,y;
    float h = 0;
    Vector2d(float px=0, float py=0);
   
    Vector2d operator+(const Vector2d& p);
    Vector2d operator-(const Vector2d& p);
    float dot(const Vector2d& p);
    float length() const;
    Vector2d max(Vector2d );
    Vector2d min(Vector2d);
   
    float operator%(const Vector2d& p); //dot product
    float operator*(const Vector2d& p); //cross product

};

