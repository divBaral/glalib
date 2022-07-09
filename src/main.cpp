#include <iostream>
#include "../include/Point.hpp"
#include "../include/MatrixTransformation2.hpp"
#include "../include/Vector2d.hpp"
#include "../include/AffineTransformation2.hpp"

typedef AffineTransformation2 af;
using namespace std;

int main()
{
    Matrix3f m;
    m = Matrix3f::ConstructByColumns(Point2d{2,2}, Vector2d{2,1}, Point2d{3,2})
;
    m.Print();

   
    
    
}