#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;
    
    double max;
    int size;  

    double sum, mean;
    double signal[4096];
    double signal_sq[4096];

    FILE * fp_r, * fp_w;

    fp_r = fopen("/home/changwan/C/cannot_read.txt","r");
    fp_w = fopen("/home/changwan/C/output.txt","w");


    if(fp_r==NULL){
            puts("fail to open a file to read!");
            return -1;
    }

  
    if(fp_w==NULL){
            puts("fail to open a file to write!");
            return -1;
    }

   n = 0;

   while (fscanf(fp_r, "%lf", &signal[n++]) !=EOF)
       ;

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
     

//write
  for (i=0; i<n-1; i++)
      fprintf(fp_w,"%10.10f \n", signal[i]);


   if(feof(fp_r)!=0)
       puts("complete to copy!");
   else
       puts("fail to copy!");

   fclose(fp_r);
   fclose(fp_w);

   return 0;
}

