#include<stdio.h>

double* sum(double signal[][4096], int x, int z)
{
  int i, k;
  int x2 = x;
  int z2 = z;
 
  double signal_sum;
  double* sum_matrix[x2];
  
  signal_sum = 0.0;
  
  printf("%d %d \n",x2, z2);

  printf("%lf \n", signal_sum);
  printf("%lf \n", sum_matrix[1]);
  
  for(i=0; i < x2; i++){
  for(k=0; k < z2; k++){
                        signal_sum = signal_sum +  signal[i][k];
                       } 
                        //printf("%lf \n", signal[i][k]);
                        *sum_matrix[i]=signal_sum;
                       }

//  printf("%lf \n", signal_sum);

  return *sum_matrix;
}
