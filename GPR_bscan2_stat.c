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
                          

//sqaure: argument in 2D matrix   
  sq_matrix = square(signal, sizeof(signal)/sizeof(signal[0]));
//         square(signal, sizeof(signal)/sizeof(signal[0]));/
//              printf("%lf \n ", sq_matrix[1][0]);  


//max: argument in 2D matrix
  max_matrix = max(sq_matrix, sizeof(sq_matrix)/sizeof(sq_matrix[0]));
  
   

/*
//dB (reference: surface reflection, a strongest value)
     for(j=0; j<y; j++){
     for(i=0; i<x; i++){ 
                          dB_str[j][i] = log10(max[j]/signal[j][i]);
                       }
                       }
*/


//#include "write.h"
#include "close.h"
   
   return 0;
}

