// For 3x3 matrix
#include "../include/MatrixTransformation2.hpp"
#include "../include/Vector.hpp"
#include "../include/Vector2d.hpp"
#include <iostream>


Matrix3f::Matrix3f() 
{
    for (int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            if ( i == j)
                mat[i][j] = 1;
            else 
                mat[i][j] = 0;
        }
    }

}
Matrix3f::Matrix3f( float a[3][3] ) 
{
     for (int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            mat[i][j] = a[i][j];
        }
    }
    
}
Matrix3f Matrix3f::Invert() 
{
    Matrix3f r;
    float det = 0;
    for(int i=0;i<3;i++)
    {
        det = det + (mat[0][i]*(mat[1][(i+1)%3]*
        mat[2][(i+2)%3] - mat[1][(i+2)%3]*mat[2][(i+1)%3]));
    }
    if(det ==0)
    {
        std::cout<<"Inverse does not exist (Determinant=0).\n";
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)  {
            r.mat[j][i] = ((mat[(i+1)%3][(j+1)%3] *
                mat[(i+2)%3][(j+2)%3]) - (mat[(i+1)%3][(j+2)%3]*
                mat[(i+2)%3][(j+1)%3]))/det;
        }
    }
    
    *this = r;
    return *this;
    // float a[n][2*n];
   
    // for (int i=0; i<n; ++i ) {
    //     for (int j=0; j<2*n; ++j) {
    //         if ( j < n )
    //             a[i][j] = mat[i][j];
    //         else {
    //             if ( j == i + n)
    //                 a[i][j] = 1;
    //             else
    //                 a[i][j] = 0;
    //         }
    //     }
    // }
    // float ratio;

    // for (int j = 0; j < n; ++j ) {
    //     if ( fabs ( a[j][j] ) == 0.0 ) {
    //         std::cout<<"Matrix3fTransformation2::Can't inverse given Matrix3f\n";
    //         assert(false);
    //     }
    //     for (int i=0; i < n; ++i) {
    //         if ( i!=j ) {
    //             ratio = a[i][j] / a[j][j];
    //             for (int k =j ; k < 2*n ; ++k )
    //                 a[i][k] -= ratio * a[j][k];
    //         }
    //     }
    // }
    // for (int i=0; i < n ; ++i) {
    //     for (int j = n; j < 2*n; ++j ) {
    //        a[i][j] = a[i][j] /a[i][i];       
    //     }
       
    // }
    // for ( int i=0; i<n; ++i ) {
    //     for ( int j=0; j<m; ++j ) {
    //         mat[i][j] = a[i][j+n];
    //     }
        
    // }
    // return *this;
}
void Matrix3f::Print()
{
    for ( int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            std::cout<<mat[i][j]<<" ";
        }
        std::cout <<std::endl;
    }   
}
Matrix3f Matrix3f::operator*(const Matrix3f &mt) 
{
    Matrix3f r;
    for ( int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            float s = 0;
            for (int k=0; k<n; ++k ) {
                s += mat[i][k]*mt.mat[k][j];
            }
            r.mat[i][j] = s;
        }
    }
   
    return r;

}
Vector2d Matrix3f::operator*( Vector2d v) 
{
    float a[n];
    float r[n];
    
    a[0]=v.x;a[1] =v.y; a[2] = 0;
    for ( int i=0; i<n; ++ i) {
        float s=0;
        for (int j=0; j<m; ++j ) {
            s+=mat[i][j]*a[j];
        }
        r[i] = s;
        

    }
    if ( r[2] != 1 ) {
        std::cout<<"Warning: Non-homogenous Matrix3f and Vector Multiplication\n";
    }
    return Vector2d(r[0], r[1]);

    

}
Point2d Matrix3f::operator*(Point2d p) 
{
   float r[n];
   float a[n];
    a[0]=p.x;a[1]=p.y; a[2] = 1;
    a[0]=p.x;a[1] =p.y; a[2] = 1;
    for ( int i=0; i<n; ++ i) {
        float s=0;
        for (int j=0; j<m; ++j ) {
            s+=mat[i][j]*a[j];
        }
        r[i] = s;
        

    }
    return Point2d(r[0],r[1]);

    

}
// Matrix3f Matrix3f::ConstructByColumns(Point2d p1, Point2d p2, Point2d p3)
// {
//     float a[3][3];
//     a[0][0]=  p1.x;
//     a[1][0] = p1.y;
//     a[2][0] = 1;

//     a[0][1]=  p2.x;
//     a[1][1] = p2.y;
//     a[2][1] = 1;

//     a[0][2]=  p3.x;
//     a[1][2] = p3.y;
//     a[2][2] = 1;

//     return Matrix3f(a);

// }
// Matrix3f Matrix3f::ConstructByColumns(Vector2d v1, Vector2d v2, Vector2d r)
// {
//     float a[3][3];
//     a[0][0]=  v1.x;
//     a[1][0] = v1.y;
//     a[2][0] = 1;

//     a[0][1]=  v2.x;
//     a[1][1] = v2.y;
//     a[2][1] = 1;

//     a[0][2]=  r.x;
//     a[1][2] = r.y;
//     a[2][2] = 1;

//     return Matrix3f(a);

// }
// template<typename T1, typename T2, typename T3>
// Matrix3f ConstructByColumns(T1 p, T2 q, T3 r)
// {
//     float a[3][3];
//     a[0][0]=  p.x;
//     a[1][0] = p.y;
//     a[2][0] = T1::h;

//     a[0][1]=  q.x;
//     a[1][1] = q.y;
//     a[2][1] = T2::h;

//     a[0][2]=  r.x;
//     a[1][2] = r.y;
//     a[2][2] = T3::h;

//     return Matrix3f(a);
// }
