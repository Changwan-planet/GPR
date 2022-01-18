#include <stdio.h>
#include <math.h>

#define SQUARE(X) ((X) * (X))
#define z 4096 #rows
#define x 2 #column

int main()
{
    int  i, k;
    int state_r, state_w;
//    double max;
//    int size;  

//    double sum, mean;

    double signal[x][z];

    FILE * fp_r;
    FILE * fp_w;

    fp_r = fopen("/home/changwan/GPR_DATA/KOREA/211027_4/B_SCAN_IMAGE_GPR.txt","r");
//     fp_r = fopen("/home/changwan/GPR/table.txt","r");
     fp_w = fopen("/home/changwan/GPR/output.txt","w");


    if(fp_r==NULL){
            puts("fail to open a file to read!");
            return -1;
    }
  
    if(fp_w==NULL){
            puts("fail to open a file to write!");
            return -1;
    }


   for(k=0;k<z;k++)
   {
       for(i=0;i<x;i++)
       {
       fscanf(fp_r, "%lf", &signal[i][k]); 
       }
   }

   for(k=0;k<z;k++)
   {
//       printf("k=%d \n",k);
       for(i=0;i<x;i++)
       {
//           printf("i=%d \n",i);
           printf("%f ", signal[i][k]);
       }
           printf("\n");
     
   }

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

   for (k=0;k<z;k++)
   {   
       for (i=0;i<x;i++)
       {
           fprintf(fp_w,"%f ", signal[i][k]);
       }  
       fprintf(fp_w,"\n");      
   }


//close   
   state_r=fclose(fp_r);
   if(state_r !=0){
       printf("error occurred while removing stream");
       return 1;
   }

   state_w=fclose(fp_w);
   if(state_w !=0){
       printf("error occurred while removing stream");
       return 1;
   }


   return 0;
}

