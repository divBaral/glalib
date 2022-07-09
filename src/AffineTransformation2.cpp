#include "../include/AffineTransformation2.hpp"

Matrix3f AffineTransformation2::RotateXY(double angle)
{
    float a[3][3];
    angle = angle*PI/180;
    a[0][0] = cos(angle);
    a[0][1] = -sin(angle);
    a[1][0] = sin(angle);
    a[1][1] = cos(angle);
    for (int i=0; i<3; ++i ) {
        a[2][i]=0;
        a[i][2]=0;
    }
    a[2][2] = 1;

    return Matrix3f(a);


}

Matrix3f AffineTransformation2::Translate( Vector2d v)
{
    Matrix3f m;
    m.mat[0][2] = v.x;
    m.mat[1][2] = v.y;
    return m;
}

Matrix3f AffineTransformation2::Translate( Point2d p, Point2d q)
{
    Vector2d v =  (q-p);
    return Translate(v);
}

Matrix3f AffineTransformation2::AxisScale(double x_amount, double y_amount)
{
    Matrix3f m;
    m.mat[0][0] = x_amount;
    m.mat[1][1] = y_amount;
    return m;
}
Matrix3f AffineTransformation2::RotateAboutPoint(Point2d p, double angle)
{
    Matrix3f R = RotateXY(angle);
    Matrix3f T = Translate({p.x, p.y});
    R.mat[0][2] = p.x;
    R.mat[1][2] = p.y;

    return R*T.Invert();
}

Matrix3f AffineTransformation2::PointsToPoints(Point2d p1, Point2d p2, Point2d p3,Point2d q1, Point2d q2, Point2d q3)
{
    Matrix3f P = Matrix3f::ConstructByColumns(p1,p2,p3);
    Matrix3f Q = Matrix3f::ConstructByColumns(q1,q2,q3);

    return Q*P.Invert();
   

}
Matrix3f AffineTransformation2::PointAndVectorsToPointAndVectors(Point2d p1, Vector2d v1, Vector2d v2,
    Point2d q1, Vector2d w1, Vector2d w2)
{
    Matrix3f P = Matrix3f::ConstructByColumns(p1,v1,v2);
    Matrix3f Q = Matrix3f::ConstructByColumns(q1,w1,w2);
    return Q*P.Invert();
}
Matrix3f AffineTransformation2::PointsAndVectorToPointsAndVector(Point2d p1, Point2d p2, Vector2d v1,
    Point2d q1, Point2d q2, Vector2d w1)
{
    Matrix3f P = Matrix3f::ConstructByColumns(p1,p2,v1);
    Matrix3f Q = Matrix3f::ConstructByColumns(q1,q2,w1);
    return Q*P.Invert();
    
}