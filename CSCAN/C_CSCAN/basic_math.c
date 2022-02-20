#include <stdlib.h>
#include <stdio.h>
#include "define.h"

double **matrix_sq(double matrix1[][xx], int z, int x){
    int i, k;
    static double **matrix3;

    //printf("%d %d", y,x);
    matrix3 = malloc(sizeof(double*) * xx);
     
    for(k = 0; k < zz; k++) {
        matrix3[k] = malloc(sizeof(double*) * zz);
    }
 
    for(k = 0; k < zz; k++){
        for(i = 0; i < xx; i++){
            matrix3[k][i] = matrix1[k][i] * matrix1[k][i];
        }
    }
    return matrix3;


}
 
/*
double **square(double matrix1[], int z){
    int k;
    double **matrix2;

    //printf("%d %d", y,x);
    matrix2 = malloc(sizeof(double*) * z);
     
    for(k = 0; k < z; k++) {
        matrix2[k] = malloc(sizeof(double*));
    }
 
    for(k = 0; k < z; k++){
            matrix2[k] = matrix1[k] * matrix1[k];
        }
    
    return matrix2;
}
*/ 
