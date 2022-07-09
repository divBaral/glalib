#pragma once

struct Vector2d
{
    float x,y;
    const static int h = 0;
    Vector2d(float px=0, float py=0);
    Vector2d operator+(const Vector2d& p);
    Vector2d operator-(const Vector2d& p);
    float operator%(const Vector2d& p); //dot product
    float operator*(const Vector2d& p); //cross product

};