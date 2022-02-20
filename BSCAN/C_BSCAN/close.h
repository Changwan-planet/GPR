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

