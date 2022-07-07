// For 3x3 matrix
#include "include/MatrixTransformation2.hpp"
#include "include/Vector.hpp"
#include "include/Vector2d.hpp"
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
Matrix3f Matrix3f::invert() 
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
            std::cout<<"Matrix3fTransformation2::Can't inverse given Matrix3f\n";
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
void Matrix3f::print()
{
    for ( int i=0; i<n; ++i ) {
        for ( int j=0; j<m; ++j ) {
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
            if ( fabs(s) < 1e-5 ) s=0.0;
            r.mat[i][j] = s;
        }
    }
    return r;

}
Vector2d Matrix3f::operator*(const Vector2d &v) 
{
    float a[n];
    float r[n];
    
    a[0]=v.x;a[1] =v.y; a[2] = 1;
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
Vector Matrix3f::operator*(const Vector &v) 
{
   float r[n];
   float a[n];
    a[0]=v.x;a[1]=v.y; a[2] = v.z;
    a[0]=v.x;a[1] =v.y; a[2] = 1;
    for ( int i=0; i<n; ++ i) {
        float s=0;
        for (int j=0; j<m; ++j ) {
            s+=mat[i][j]*a[j];
        }
        r[i] = s;
        

    }
    return Vector(r[0], r[1],r[2]);

    

}

