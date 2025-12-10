#include "matrixOp.h"
#include<stdio.h>


void elemMult(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result){
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            result[i][k] = a[i][k] * b[i][k];
        }
    }
}

void mult(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result){
    for(int i = 0; i<3; i++ ){
        for(int k = 0; k<3; k++){
            result[i][j] =
                a[i][0] * b[0][j] +
                a[i][1] * b[1][j] +
                a[i][2] * b[2][j];
        }
    }
}

void transpose(Matrix3x3 a, Matrix3x3 result){
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            result[i][k] = a[k][i];
        }
    }
}

float det3x3(Matrix3x3 a){
    return
        a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
        a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
        a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

float det2x2(int m[2][2]){
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

void adjoint(Matrix3x3 a, Matrix3x3 result) {
    Matrix3x3 cofactor;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int minor[2][2];
            int mi = 0, mj = 0;

            // Build minor matrix by skipping row i, column j
            for (int r = 0; r < 3; r++) {
                if (r == i) continue;
                mj = 0; // reset col of minor row
                for (int c = 0; c < 3; c++) {
                    if (c == j) continue;

                    minor[mi][mj] = a[r][c];
                    mj++;
                }
                mi++;
            }

            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            cofactor[i][j] = sign * det2x2(minor);
        }
    }

    // adjoint = transpose of cofactor matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = cofactor[j][i];
        }
    }
}


void inverse(Matrix3x3 a, float result[3][3]) {
    float det = det3x3(a);

    if (det == 0) {
        printf("Matrix is not invertible!\n");
        return;
    }

    Matrix3x3 adj;
    adjoint(a, adj);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
}
