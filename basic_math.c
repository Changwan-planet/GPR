#include<stdio.h>

double * sum(const double signal[][4],int y)
{
  int i, j;
  int x2 = sizeof(signal[0])/sizeof(double);
  int y2 = y;
 
  double  signal_sum;
  static double temp_sum[sizeof(signal[0])/sizeof(double)];
//to return the address of a local variable to outside of the function.
  
  printf("%d %d \n",y2, x2);

  for(i=0; i < x2; i++){
                         signal_sum = 0.0;
  for(j=0; j < y2; j++){
                        signal_sum += signal[j][i];
                       } 
                        temp_sum[i]=signal_sum;
//printf("i=%d sum=%p \n",  i, signal_sum);                     
//                        printf("i=%d sum=%lf \n",  i, temp_sum[i]);    
                       }

  return temp_sum;
}

double * square(const double signal[][4],int y)
{
  int i, j;
 static int x3 = sizeof(signal[0])/sizeof(double);
  int y3 = y;
  
//static  double (*temp_sq)[4];
 // double temp_sq=signal
static double  temp_sq[sizeof(signal)/sizeof(signal[0])][sizeof(signal[0])/sizeof(double)];   
// static double  temp_sq[3][4];   

 //  static double  temp_sq[y2][sizeof(signal[0])/sizeof(double)];   
 
  //to return the address of a local variable to outside of the function.
  
  printf("%d %d \n",y3, x3);

  for(i=0; i < x3; i++){
  for(j=0; j < y3; j++){
                        temp_sq[j][i] = signal[j][i] * signal[j][i];                    
//printf("i=%d sum=%p \n",  i, signal_sum);                     
                        printf("j=%d i=%d sq=%lf \n", j,  i, temp_sq[j][i]);    
                       }
                       }
    return temp_sq;
//  return (temp_sq)[4];
}

