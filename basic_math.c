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
  //static int x3 = sizeof(signal[0])/sizeof(double);
  int x3 = xx;
  int y3 = y;
  //double temp;
  double  **temp_sq;   
  double **test;  //disallocation test

  //to return the address of a local variable to outside of the function.
   //temp_sq = (double*) malloc(3 *sizeof(double));
  
  temp_sq = malloc(sizeof(double *) * x3);

  for(int j = 0; j < y3; j++){ 
                              temp_sq[j] = malloc(sizeof(double *) * y3);
                              }

  printf("++++++square++++++ \n");
  //printf("%d %d \n",y3, x3);
    
  for(int i=0; i < x3; i++){
  for(int j=0; j < y3; j++){
                           temp_sq[j][i] = signal[j][i] * signal[j][i];    
      //         printf("j=%d i=%d sq=%lf \n", j,  i, **temp_sq[j][i]);    
                           }
                           }    
     return temp_sq;
     for(int j=0; j < yy; j++){
                               free(temp_sq[j]);
                              }
     free(temp_sq);     
}

//sum: in_put: 2D matrix / out_put: 1D matrix.
double * matrix(const double sq_matrix[][xx],int y)
{
  int x2 = sizeof(sq_matrix[0])/sizeof(double);
  int y2 = y;
 
  double  signal_sum;
  static double temp_sum[sizeof(sq_matrix[0])/sizeof(double)];
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


