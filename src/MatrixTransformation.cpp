// For 3x3 matrix
#include "../include/MatrixTransformation.hpp"
#include "../include/Vector.hpp"

#include <cassert>
#include <iostream>


Matrix4f::Matrix4f() 
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
Matrix4f::Matrix4f( float a[4][4] ) 
{
    for (int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            mat[i][j] = a[i][j];
        }
    }
    
}
Matrix4f::Matrix4f(float a11, float a12, float a13, float a14,
             float a21, float a22, float a23, float a24, 
             float a31, float a32, float a33, float a34,
             float a41, float a42, float a43, float a44 )
{
    mat[0][0] =  a11, mat[0][1] =  a12, mat[0][2] =  a13, mat[0][3] =  a14,
    mat[1][0] =  a21, mat[1][1] =  a22, mat[1][2] =  a23, mat[1][3] =  a24, 
    mat[2][0] =  a31, mat[2][1] =  a32, mat[2][2] =  a33, mat[2][3] =  a34,
    mat[3][0] =  a41, mat[3][1] =  a42, mat[3][2] =  a43, mat[3][3] =  a44;


}
Matrix4f::Matrix4f(const Matrix3f& m3)
{
    for (int i=0; i<3; ++i ) {
        for ( int j=0; j<3; ++j ) {
            mat[i][j] = m3.mat[i][j];
        }
    }
    for ( int i=0; i<4; ++i ) {
        mat[i][3] = 0;
        mat[3][i] = 0;
    }
    mat[3][3] = 1;
    
}
Matrix4f Matrix4f::Pinvert() 
{
    
    float a[n][2*n];
   
    for (int i=0; i<n; ++i ) {
        for (int j=0; j<2*n; ++j) {
            if ( j < n )
                a[i][j] = mat[i][j];
            else {
                if ( j == i + n)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
    }
    float ratio;
    for (int j = 0; j < n; ++j ) {
        if ( fabs ( a[j][j] ) < 1e-7 ) {
            std::cout<<"Matrix4fTransformation2::Can't inverse given Matrix4f\n";
            assert(false);
        }
        for (int i=0; i < n; ++i) {
            if ( i!=j ) {
                ratio = a[i][j] / a[j][j];
                for (int k =j ; k < 2*n ; ++k )
                    a[i][k] -= ratio * a[j][k];
            }
        }
    }
    for (int i=0; i < n ; ++i) {
        for (int j = n; j < 2*n; ++j ) {
           a[i][j] = a[i][j] /a[i][i];       
        }
       
    }
    for ( int i=0; i<n; ++i ) {
        for ( int j=0; j<m; ++j ) {
            mat[i][j] = a[i][j+n];
        }
        
    }
    return *this;
}
void Matrix4f::Print()
{
    for ( int i=0; i<n; ++i ) {
        for ( int j=0; j<m; ++j ) {
            std::cout<<mat[i][j]<<"    ";
        }
        std::cout <<std::endl;
    }   
}
Matrix4f Matrix4f::operator*(const Matrix4f &mt) 
{
    Matrix4f r;
    for ( int i=0; i<m; ++i ) {
        for ( int j=0; j<n; ++j ) {
            float s = 0;
            for (int k=0; k<n; ++k ) {
                s += mat[i][k]*mt.mat[k][j];
            }
            if ( fabs(s) < 1e-5 ) s=0.0;
            r.mat[i][j] = s;
        }
    }
    return r;

}
Vector Matrix4f::operator*( Vector v) 
{
    float a[n];
    float r[n];
    
    a[0]=v.x;a[1] =v.y;a[2]=v.z ;a[3] = 0;
    for ( int i=0; i<n; ++ i) {
        float s=0;
        for (int j=0; j<m; ++j ) {
            s+=mat[i][j]*a[j];
        }
        r[i] = s;
        

    }
    if ( r[3] != 1 ) {
        std::cout<<"Warning: Non-homogenous Matrix4f and Vector Multiplication\n";
    }
    return Vector(r[0], r[1],r[2]);

    

}
Point Matrix4f::operator*(Point p) 
{
   float r[n];
   float a[n];
    a[0]=p.x;a[1]=p.y; a[2] = p.z;a[3] = Point::h;
    a[0]=p.x;a[1] =p.y; a[2]=p.z; a[3] = Point::h;
    for ( int i=0; i<n; ++ i) {
        float s=0;
        for (int j=0; j<m; ++j ) {
            s+=mat[i][j]*a[j];
        }
        r[i] = s;
    }
    return Point(r[0],r[1],r[2]);

    

}

Matrix4f Matrix4f::Invert()
{

    double m[16];
    for( int i=0; i<n; ++i ) {
        for ( int j=0; j<n; ++j ) {
            m[i+4*j] = mat[i][j];
        }
    }
    double inv[16], det;
 

    inv[0] = m[5]  * m[10] * m[15] - 
             m[5]  * m[11] * m[14] - 
             m[9]  * m[6]  * m[15] + 
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] - 
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] + 
              m[4]  * m[11] * m[14] + 
              m[8]  * m[6]  * m[15] - 
              m[8]  * m[7]  * m[14] - 
              m[12] * m[6]  * m[11] + 
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] - 
             m[4]  * m[11] * m[13] - 
             m[8]  * m[5] * m[15] + 
             m[8]  * m[7] * m[13] + 
             m[12] * m[5] * m[11] - 
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] + 
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] - 
               m[8]  * m[6] * m[13] - 
               m[12] * m[5] * m[10] + 
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] + 
              m[1]  * m[11] * m[14] + 
              m[9]  * m[2] * m[15] - 
              m[9]  * m[3] * m[14] - 
              m[13] * m[2] * m[11] + 
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] - 
             m[0]  * m[11] * m[14] - 
             m[8]  * m[2] * m[15] + 
             m[8]  * m[3] * m[14] + 
             m[12] * m[2] * m[11] - 
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] + 
              m[0]  * m[11] * m[13] + 
              m[8]  * m[1] * m[15] - 
              m[8]  * m[3] * m[13] - 
              m[12] * m[1] * m[11] + 
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] - 
              m[0]  * m[10] * m[13] - 
              m[8]  * m[1] * m[14] + 
              m[8]  * m[2] * m[13] + 
              m[12] * m[1] * m[10] - 
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] - 
             m[1]  * m[7] * m[14] - 
             m[5]  * m[2] * m[15] + 
             m[5]  * m[3] * m[14] + 
             m[13] * m[2] * m[7] - 
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] + 
              m[0]  * m[7] * m[14] + 
              m[4]  * m[2] * m[15] - 
              m[4]  * m[3] * m[14] - 
              m[12] * m[2] * m[7] + 
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] - 
              m[0]  * m[7] * m[13] - 
              m[4]  * m[1] * m[15] + 
              m[4]  * m[3] * m[13] + 
              m[12] * m[1] * m[7] - 
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] + 
               m[0]  * m[6] * m[13] + 
               m[4]  * m[1] * m[14] - 
               m[4]  * m[2] * m[13] - 
               m[12] * m[1] * m[6] + 
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] + 
              m[1] * m[7] * m[10] + 
              m[5] * m[2] * m[11] - 
              m[5] * m[3] * m[10] - 
              m[9] * m[2] * m[7] + 
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] - 
             m[0] * m[7] * m[10] - 
             m[4] * m[2] * m[11] + 
             m[4] * m[3] * m[10] + 
             m[8] * m[2] * m[7] - 
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] + 
               m[0] * m[7] * m[9] + 
               m[4] * m[1] * m[11] - 
               m[4] * m[3] * m[9] - 
               m[8] * m[1] * m[7] + 
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] - 
              m[0] * m[6] * m[9] - 
              m[4] * m[1] * m[10] + 
              m[4] * m[2] * m[9] + 
              m[8] * m[1] * m[6] - 
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    assert(det!=0);

    det = 1.0 / det;
     for( int i=0; i<n; ++i ) {
        for ( int j=0; j<n; ++j ) {
            mat[i][j] = inv[i+4*j]*det;
        }
    }
    // for (i = 0; i < 16; i++)
    //     invOut[i] = inv[i] * det;
    return *this;
    
}
