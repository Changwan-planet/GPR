#include <stdio.h>
#include <math.h>

#define SQUARE(X) ((X) * (X))
#define z 4096
#define x 2

int main(void)
{
    int  i, j;
    
//    double max;
//    int size;  

//    double sum, mean;
    double signal[x][z];
//    double signal_sq[8][4096];

    FILE * fp_r, * fp_w;

    fp_r = fopen("/home/changwan/GPR_DATA/KOREA/211027_4/B_SCAN_IMAGE_GPR.txt","r");
    fp_w = fopen("/home/changwan/GPR/output.txt","w");


    if(fp_r==NULL){
            puts("fail to open a file to read!");
            return -1;
    }

  
    if(fp_w==NULL){
            puts("fail to open a file to write!");
            return -1;
    }


   for(j=0;j<x-1;j++)
   for(i=0;i<z-1;i++)
       fscanf(fp_r, "%lf", &signal[i][j]); 
       
   for(j=0;j<z-1;j++)
      printf("%f \n", signal[1][i]);
/*   
//sum
   for(i=0;i<n-1;i++)
      sum = sum + signal[i];     
//size
   size = sizeof(signal)/sizeof(double);
   printf("size=%d",size);

//mean
   mean = sum/size;

//   for (i=0; i<n-1; i++)
//       printf("%10.10f \n",fval[i]);
   
   printf("\n");
   printf("+++++++++++++++++++++ \n");
   printf("sum=%10.10f \n",sum);
   printf("size=%d \n", size);
   printf("mean=%f \n", mean);

//square
   for (i=0;i<n-1;i++)
       signal_sq[i]=signal[i]*signal[i];

//max
 max= signal_sq[0];
    for (i=0;i<n-1;i++) 
    {    
        if (signal_sq[i] > max)
        {
            max = signal_sq[i];
            j = i;
        }
    }   
      printf("max=%f %d\n", max, j);            
                         
//dB
     
*/

//write

   for (j=0;j<z-1;j++)
//   for (j=0;j<x-1;j++)
       fprintf(fp_w,"%f \n", signal[1][j]);

   if(feof(fp_r)!=0)
       puts("complete to copy!");
   else
       puts("fail to copy!");

   fclose(fp_r);
   fclose(fp_w);

   return 0;
}

