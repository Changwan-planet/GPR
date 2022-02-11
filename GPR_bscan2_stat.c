#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"
#include "basic_math.h"


int main()
{
    #include "variables.h"
    #include "open_read.h"

//sum: argument is 2D matrix
   sum_matrix = sum(signal, sizeof(signal)/sizeof(signal[0]));
        
//       for(i=0; i < x; i++){
//           printf("%lf \n",sum_matrix[i]);
//                           }
//           printf("%lf \n",sum_matrix[4]);                          

//sqaure: argument in 2D matrix   
  sq_matrix = square(signal, sizeof(signal)/sizeof(signal[0]));
//         square(signal, sizeof(signal)/sizeof(signal[0]));/
              printf("%lf ", sq_matrix[1][0]);  
/*
//max
     for (j=0; j<y; j++){
                          max[j] = signal_sq[0];
     for (i=0; i<x; i++){                       
                          if (signal_sq[j] > max[j]){
                                                      max[j] = signal_sq[j];
                                                      t = j;
                                                    } 
                        } 
//       printf("max=%lf survey_point=%d max_loc=%d \n", max[j], i, t);
                        }

//dB (reference: surface reflection, a strongest value)
     for(j=0; j<y; j++){
     for(i=0; i<x; i++){ 
                          dB_str[j][i] = log10(max[j]/signal[j][i]);
                       }
                       }

#include "write.h"
*/

#include "close.h"
   
//free the memory              
//   for (int j=0; j < yy; j++){
//                              free(sq_matrix[j]);
//                             }
//   printf("%p \n", &sq_matrix); 
//   free(sq_matrix);
//   printf("%p \n", &sq_matrix[1]); 
 
   return 0;
}

