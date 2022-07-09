// For 3x3 matrix
#include "../include/MatrixTransformation.hpp"
#include "../include/Vector.hpp"

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
Matrix4f Matrix4f::Invert() 
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
            std::cout<<mat[i][j]<<" ";
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
