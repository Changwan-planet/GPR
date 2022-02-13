#include <stdlib.h>
#include <stdio.h>

double **matrix_sum(double matrix1[][101], int y, int x){
    int i, j;
    double **matrix3;

    //printf("%d %d", y,x);
    matrix3 = malloc(sizeof(double*) * x);
     
    for(j = 0; j < y; j++) {
        matrix3[j] = malloc(sizeof(double*) * y);
    }
 
    for(j = 0; j < y; j++){
        for(i = 0; i < x; i++){
            matrix3[j][i] = matrix1[j][i] * matrix1[j][i];
        }
    }
    return matrix3;
}
 
