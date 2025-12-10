#ifndef MATRIXOP_H
#define MATRIXOP_H

typedef int Matrix3x3[3][3];

void elemMult(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void mult(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void transpose(Matrix3x3 a, Matrix3x3 result);
float  det3x3(Matrix3x3 a);
float  det2x2(int m[2][2]);
void adjoint(Matrix3x3 a, Matrix3x3 result);
void inverse(Matrix3x3 a,  float result[3][3]);

#endif
