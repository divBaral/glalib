// This contains:
// A parent class for linear, afﬁne, and projective
// transformations.
#include "MatrixTransformation.hpp"
#include "Point.hpp"
#include <cmath>
#ifndef PI
    #define PI 3.141516
#endif

class AffineTransformation
{
public:
    static Matrix4f RotateXY(double angle);
    static Matrix4f Translate( Vector v);
    static Matrix4f Translate(Point p, Point q);
    static Matrix4f AxisScale(double x_amount, double y_amount, double z_amount) ;
    static Matrix4f RotateAboutPoint(Point p, double angle);
    static Matrix4f PointsToPoints(Point p1, Point p2, Point p3,Point p4,
                                    Point q1, Point q2, Point q3, Point q4 );
    static Matrix4f PointAndVectorsToPointAndVectors(Point p1, Vector v1, Vector v2,Vector v3,
                                                         Point q1, Vector w1, Vector w2, Vector w3);
    static Matrix4f PointsAndVectorToPointsAndVector(Point p1, Point p2, Point p3, Vector v1,
                                                         Point q1, Point q2,Point q3, Vector w1);

};