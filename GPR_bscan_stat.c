#include <stdio.h>
#include <math.h>
#include "basic_math.h"

#define SQUARE(X) ((X) * (X))
#define z 4096 //rows
#define x 101 //column

int main()
{
//    #include "struct"
    #include "variables.h"
    #include "open_read.h"

//sum
//    for(i=0; i<x; i++)
 //      sum += signal[1][k];
         sum(signal, x, z);
         //sum_matrix = sum(signal,x,z);
         //printf("%10.10lf \n",sum_matrix);


/*
//square
    for (i=0; i<x; i++){
    for (k=0; k<z; k++){
        signal_sq[k]=signal[i][k] * signal[i][k];
                       }
                       }
//max
     for (i=0; i<x; i++){
                          max[i] = signal_sq[0];
     for (k=0; k<z; k++){                       
                          if (signal_sq[i] > max[i]){
                                                      max[i] = signal_sq[i];
                                                      t = i;
                                                    } 
                        } 
//       printf("max=%lf survey_point=%d max_loc=%d \n", max[i], i, t);
                        }

//dB (reference: surface reflection, a strongest value)
     for(i=0; i<x; i++){
     for(k=0; k<z; k++){ 
                          dB_str[i][k] = log10(max[i]/signal[i][k]);
                       }
                       }

#include "write.h"
*/

#include "close.h"

   return 0;
}

