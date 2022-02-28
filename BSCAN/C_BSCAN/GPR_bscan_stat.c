#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"
#include "basic_math2.h"

int main()
{
    #include "variables.h"
    #include "open_read.h"
 
//square: 1D array -> 1D array (a column, 1 pulse(scan)).
   printf("++++++square++++++\n");
   for(int i=0; i<x; i++){
                           sq_temp=&signal[0][i];
   for(int j=0; j<y; j++){                                    
                           sq_signal[j]=*sq_temp;
                           sq_temp = sq_temp + x;  
                         }                 
          sq_matrix = square(sq_signal, sizeof(sq_signal)/sizeof(double)); 

   for(int j=0; j<y; j++){
               //printf("j=%d i=%d %lf \n",j, i, sq_matrix[j]);             
               sq_matrix2[j][i] = sq_matrix[j];
                         }
             //printf("\n");
                         }
//print sq_matrix
//   for(int i=0; i<x; i++){
//   for(int j=0; j<y; j++){
//                      printf("j=%d i=%d %lf\n",j, i, sq_matrix2[j][i]);
//                         }
//                        }

//max: 1D array -> 1D array (a column, 1 pulse(scan)).
   printf("++++++max++++++\n");
   for(int i=0; i<x; i++){
                           max_temp=&sq_matrix2[0][i];
   for(int j=0; j<y; j++){                                    
                           max_signal[j]=*max_temp;
                           max_temp = max_temp + x;  
                         }                 
          max_matrix = max(max_signal, sizeof(max_signal)/sizeof(double)); 
            
               max_matrix2[i] = max_matrix;

//               printf("i=%d %lf \n", i, max_matrix2[i]);          
//               printf("i=%d \n", i);          
//               printf("\n");
                         }
//print max
//   for(int i=0; i<x; i++){
//                       printf("i=%d %lf\n",i, max_matrix2[i]);
//                         }

     
//dB (reference: surface reflection, a strongest value)
     printf("++++++dB++++++\n");     
     //for(int j=0; j<y; j++){
     
     for(int i=0; i<x; i++){ 
     for(int j=0; j<y; j++){
      
                // dB_str[j][i] = 10 * log10(max_matrix2[i]/sq_matrix2[j][i]);
                dB_str[j][i] = 10 * log10(sq_matrix2[j][i]/max_matrix2[i]);
                   
//      printf("j=%d i=%d %lf\n", j,i,dB_str[j][i]);
                           }
                           }

#include "write.h"
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

