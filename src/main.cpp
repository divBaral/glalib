#include <iostream>
#include "../include/Point.hpp"
#include "../include/MatrixTransformation2.hpp"
#include "../include/MatrixTransformation.hpp"

#include "../include/Vector2d.hpp"
#include "../include/AffineTransformation2.hpp"
#include "../include/AffineTransformation.hpp"


typedef AffineTransformation2 af2;
typedef AffineTransformation af;
using namespace std;

int main()
{
Point P(1,1,1);
auto T = AffineTransformation::Translate(Vector(3,1,2));
auto S = AffineTransformation::RotateXY(30);
Point Q = (S * T) * P;
cout<<Q.x<<" "<<Q.y<<" "<<Q.z;

}