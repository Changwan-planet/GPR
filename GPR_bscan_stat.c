#include <stdio.h>
#include <math.h>
#include "basic_math.h"

//#define y 3 //rows j
//#define x 4 //column i

int main()
{
//    #include "struct"
    #include "variables.h"
    #include "open_read.h"

//sum

   sum_matrix = sum(signal, sizeof(signal)/sizeof(signal[0]));
        
       for(i=0; i < x; i++){
           printf("%lf \n",sum_matrix[i]);
                           }
           printf("%lf \n",sum_matrix[4]);                          

//square
   sq_matrix = square(signal, sizeof(signal)/sizeof(signal[0]));
      
      for(j=0; j < y; j++){
      for(i=0; i < x; i++){
           printf("%lf \n",sq_matrix[j][i]);
                           }
                           }

      

/*
//square
    for (i=0; i<x; i++){
    for (j=0; j<y; j++){
        signal_sq[j]=signal[j][i] * signal[j][i];
                       }
                       }
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

   return 0;
}

