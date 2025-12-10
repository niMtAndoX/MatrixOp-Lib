#include <stdio.h>
#include "matrixOp.h"

void printMatrix(Matrix3x3 a);
void printMatrixFloat(float a[3][3]);

int main(){
    Matrix3x3 A;
    Matrix3x3 B;
    Matrix3x3 R;      // for int results (elemMult, mult, transpose, adjoint)
    float Inv[3][3];  // for inverse (float result)

    for(int i = 0; i<3; i++){
        for(int k = 0; k<3;k++){
            int input;
            printf("Please enter number for index [%d][%d] of matrix A:\n", i, k);
            scanf("%d", &input);
            A[i][k] = input;
        }
    }
    printf("\n");
    for(int i = 0; i<3; i++){
        for(int k = 0; k<3;k++){
            int input;
            printf("Please enter number for index [%d][%d] of matrix B:\n", i, k);
            scanf("%d", &input);
            B[i][k] = input;
        }
    }

    printf("\nMatrix A\n");
    printMatrix(A);

    printf("Matrix B\n");
    printMatrix(B);

    printf("A * B element wise\n");
    elemMult(A, B, R);
    printMatrix(R);

    printf("A * B\n");
    mult(A, B, R);
    printMatrix(R);

    printf("Transpose A\n");
    transpose(A, R);
    printMatrix(R);

    printf("Determinant of A\n");
    printf("%f\n", det3x3(A));

    printf("Adjoint A\n");
    adjoint(A, R);
    printMatrix(R);

    printf("Inverse of A\n");
    inverse(A, Inv);
    printMatrixFloat(Inv);

    return 0;
}

void printMatrix(Matrix3x3 a){
    for(int i = 0; i<3; i++){
        for(int k = 0; k<3;k++){
            printf("%d, ", a[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrixFloat(float a[3][3]){
    for(int i = 0; i<3; i++){
        for(int k = 0; k<3;k++){
            printf("%f, ", a[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}