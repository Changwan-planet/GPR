#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "define.h"

//sum: in_put: 2D matrix / out_put: 1D matrix.
double * sum(const double signal[][xx],int y)
{
  int x2 = sizeof(signal[0])/sizeof(double);
  int y2 = y;
 
  double  signal_sum;
  static double temp_sum[sizeof(signal[0])/sizeof(double)];
//to return the address of a local variable to outside of the function.
  
  printf("++++++sum++++++\n");
  printf("%d %d \n",y2, x2);

  for(int i=0; i < x2; i++){
                         signal_sum = 0.0;
  for(int j=0; j < y2; j++){
                        signal_sum += signal[j][i];
                       } 
                        temp_sum[i]=signal_sum;
//printf("i=%d sum=%p \n",  i, signal_sum);                     
//                        printf("i=%d sum=%lf \n",  i, temp_sum[i]);    
                       }
  return temp_sum;
}

//out 1 column data
/*
double * square( double *sq_signal, int y)
{
  int y3=y;
  static double  temp_sq[yy];   
  //static double * temp_sq2[yy];
  //to return the address of a local variable to outside of the function.
  
  //temp_sq = (double*) malloc(3 *sizeof(double));

  for(int j=0; j < y3; j++){
                        temp_sq[j] = sq_signal[j] * sq_signal[j];             
//                        printf("j=%d sq=%lf \n", j,  temp_sq[j]);
                           }                      
    return temp_sq;
}

*/

//square: in_put: 2D matrix out_put: 2D matrix
double ** square( double signal[][xx],int y)
{
  int x3 = xx;
  int y3 = y;
  //double temp;
  double  **temp_sq;   
  //to return the address of a local variable to outside of the function.
  //temp_sq = (double*) malloc(3 *sizeof(double));
 
  printf("++++++square++++++ \n");
  printf("%d %d \n",y3, x3);
     
  temp_sq = malloc(sizeof(double *) * x3);

  for(int j = 0; j < y3; j++){ 
                              temp_sq[j] = malloc(sizeof(double *) * y3);
                              }
   
  //for(int i=0; i < x3; i++){
  int i=3;
   for(int j=0; j < y3; j++){
                           temp_sq[j][i] = signal[j][i] * signal[j][i];    
     //           printf("j=%d i=%d sq=%lf \n", j,  i, temp_sq[j][i]);    
                  printf("j=%d i=%d sq=%lf \n", j,  i, signal[j][i]);    
                           
                            }
    //                       }    
     return temp_sq;
     
     //for(int j=0; j < yy; j++){
     //                          free(temp_sq[j]);
     //                         }
     //free(temp_sq);     
}

//sum: in_put: 2D matrix / out_put: 1D matrix.
double * max(double **sq_matrix,int y)
{
  int x4 = xx;
  int y4 = yy;
 
  int i,j, t;
  static double  temp_sq_max[xx];
  
//to return the address of a local variable to outside of the function

  printf("++++++max++++++\n");
  printf("%d %d \n",y4, x4);

  for( j=0; j < y4; j++){
                             temp_sq_max[j] = sq_matrix[j][0];
  for( i=0; i < x4; i++){
                             if ( sq_matrix[j][i] > temp_sq_max[j] ) {  
                                                       temp_sq_max[j] = sq_matrix[j][i];  
                                                                  t = j;
                                                                     }
 
                            }
               printf("max=%lf j_max_loc=%d i_max_loc=%d \n", temp_sq_max[j],j, i);

                            }
   return temp_sq_max;
}


