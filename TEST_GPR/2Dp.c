#include <stdio.h>
#include <stdlib.h>
 
#include "basic_math.h"
 
int main(){
    
    #include "variables.h"
    #include "open_read.h"
    

    sq_matrix = matrix_sum(signal, y, x); //asigning
    printf("The sum of the matrix is: \n");
    for(int j = 0; j < y; j++){
        for(int i = 0; i < x; i++){
            printf("%lf",sq_matrix[j][i]);
            printf("\t");
        }
        printf("\n");
    }
 
    //free the memory
    for(int j = 0; j < y; j++) {
        free(sq_matrix[j]);
    }
    free(sq_matrix);
    return 0;
}
