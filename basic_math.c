#include <stdio.h>


double * sum(const double signal[][101],int y)
{
  int x2 = sizeof(signal[0])/sizeof(double);
  int y2 = y;
 
  double  signal_sum;
  static double temp_sum[sizeof(signal[0])/sizeof(double)];
//to return the address of a local variable to outside of the function.
  
  printf("++++++sum++++++");
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

double * square( const double signal[][101],int y)

{
  static int x3 = sizeof(signal[0])/sizeof(double);
  int y3 = y;
  static double  temp_sq[4096][101];   
  //to return the address of a local variable to outside of the function.
  
  printf("++++++square++++++");
  printf("%d %d \n",y3, x3);

  for(int i=0; i < x3; i++){
  for(int j=0; j < y3; j++){
                        temp_sq[j][i] = signal[j][i] * signal[j][i];                    
//printf("i=%d sum=%p \n",  i, signal_sum);                     
//                        printf("j=%d i=%d sq=%lf \n", j,  i, temp_sq[j][i]);    
                       }
                       }
    return temp_sq;
}

