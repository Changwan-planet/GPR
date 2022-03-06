//close   
   state_r1=fclose(fp_r1);
   if(state_r1 !=0){
       printf("error occurred while removing stream");
       return 1;
   }

   state_r2=fclose(fp_r2);
   if(state_r2 !=0){
       printf("error occurred while removing stream");
       return 1;
   }


   state_w=fclose(fp_w);
   if(state_w !=0){
       printf("error occurred while removing stream");
       return 1;
   }

