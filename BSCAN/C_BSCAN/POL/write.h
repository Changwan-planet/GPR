//write

   for (int j=0; j<y; j++){
   for (int i=0; i<x; i++){
                           //fprintf(fp_w,"%lf ", signal[j][i]);
                           fprintf(fp_w,"%lf ", dif_dB[j][i]);
                      }  
                       fprintf(fp_w,"\n");      
                      } 
