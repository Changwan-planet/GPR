#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "basic_math.h"

int main()
{

#include "variables.h"    
#include "open_read.h"

//square    
  for (int k=0; k < zz; k++){
  for (int i=0; i < xx; i++){  
     
      bsg_temp = &signal[k][0][i];
      B_signal[k][i]=*bsg_temp;
      bscan =  matrix_sq( B_signal, zz, xx);
      
                           }
                           }

//#include "write.h" 
#include "close.h"
#include "free.h"

  return 0;
}             
