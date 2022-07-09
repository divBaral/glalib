#include "../include/AffineTransformation.hpp"

Matrix4f AffineTransformation::RotateXY(double angle)
{
    float a[4][4];
    angle = angle*PI/180;
    a[0][0] = cos(angle);
    a[0][1] = -sin(angle);
    a[1][0] = sin(angle);
    a[1][1] = cos(angle);
    for (int i=0; i<4; ++i ) {
        a[2][i]=0;
        a[i][2]=0;
    }
    a[2][2] = 1;
     for (int i=0; i<4; ++i ) {
        a[3][i]=0;
        a[i][3]=0;
    }
    a[3][3] = 1;

    return Matrix4f(a);
    //return AffineTransformation2::RotateXY(30);
}

Matrix4f AffineTransformation::Translate( Vector v)
{
    Matrix4f m;
    m.mat[0][3] = v.x;
    m.mat[1][3] = v.y;
    m.mat[2][3] = v.z;
    return m;
}

Matrix4f AffineTransformation::Translate( Point p, Point q)
{
    Vector v =  (q-p);
    return Translate(v);
}

Matrix4f AffineTransformation::AxisScale(double x_amount, double y_amount, double z_amount)
{
    Matrix4f m;
    m.mat[0][0] = x_amount;
    m.mat[1][1] = y_amount;
    m.mat[2][2] = z_amount;
    return m;
}
Matrix4f AffineTransformation::RotateAboutPoint(Point p, double angle)
{
    Matrix4f R = RotateXY(angle);
    Matrix4f T = Translate({p.x, p.y, p.z});
    R.mat[0][3] = p.x;
    R.mat[1][3] = p.y;
    R.mat[2][3] = p.z;
    return R*T.Invert();
}

Matrix4f AffineTransformation::PointsToPoints(Point p1, Point p2, Point p3 ,Point p4,Point q1, Point q2, Point q3, Point q4)
{
    Matrix4f P = Matrix4f::ConstructByColumns(p1,p2,p3,p4);
    Matrix4f Q = Matrix4f::ConstructByColumns(q1,q2,q3,q4);

    return Q*P.Invert();
   

}
Matrix4f AffineTransformation::PointAndVectorsToPointAndVectors(Point p1, Vector v1, Vector v2,Vector v3,
    Point q1, Vector w1, Vector w2, Vector w3)
{
    Matrix4f P = Matrix4f::ConstructByColumns(p1,v1,v2,v3);
    Matrix4f Q = Matrix4f::ConstructByColumns(q1,w1,w2,w3);
    return Q*P.Invert();
}
Matrix4f AffineTransformation::PointsAndVectorToPointsAndVector(Point p1, Point p2,Point p3, Vector v1,
    Point q1, Point q2, Point q3, Vector w1)
{
    Matrix4f P = Matrix4f::ConstructByColumns(p1,p2,p3, v1);
    Matrix4f Q = Matrix4f::ConstructByColumns(q1,q2,q3, w1);
    return Q*P.Invert();
    
}