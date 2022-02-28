#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "define.h"

//square 1D array -> 1D arrray
double * square( double sq_signal[yy], int y)
{
  int y3=y;
  static double temp_sq[yy];
  //to return the address of a local variable to outside of the function.

  //printf("++++++square++++++\n");
  for(int j=0; j < y3; j++){
                            temp_sq[j] = sq_signal[j] * sq_signal[j]; 
                           }                      
    return temp_sq;
}


//max: 1D array -> 1 argument
double max(double max_signal[yy],int y)
{
  int y4 = yy;
  int x4 = xx;

  int i,j, t;
  static double  temp_sq_max;
  
//to return the address of a local variable to outside of the function

//  printf("++++++max++++++\n");
//  printf("%d %d \n",y4, x4);
                         temp_sq_max = max_signal[0];
 
  for( j=0; j < y4; j++){
                         if ( max_signal[j] > temp_sq_max ) 
                            {  
                             temp_sq_max = max_signal[j];  
                             t = j;
                            }  
                         }
                        
                         printf("j_max_loc=%d max=%lf \n", t, temp_sq_max); 
                         
   return temp_sq_max;
}


