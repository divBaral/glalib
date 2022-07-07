// This contains:
// A parent class for linear, afﬁne, and projective
// transformations.
#include "MatrixTransformation2.hpp"
#include "Point2d.hpp"

class AffineTransformation2
{

    static Matrix3f RotateXY(double angle);
    static Matrix3f Translate(Vector2d v);
    static Matrix3f Translate(Point2d p, Point2d q);
    static Matrix3f AxisScale(double x_amount, double y_amount);
    static Matrix3f RotateAboutPoint(Point2d p, double angle);
    static Matrix3f PointsToPoints(Point2d p1, Point2d p2, Point2d p3,Point2d q1, Point2d q2, Point2d q3);
    static Matrix3f PointAndVectorsToPointAndVectors(Point2d p1, Vector2d v1, Vector2d v2,
    Point2d q1, Vector2d w1, Vector2d w2);
    static Matrix3f PointsAndVectorToPointsAndVector(Point2d p1, Point2d p2, Vector2d v1,
    Point2d q1, Point2d q2, Vector2d w1);

};