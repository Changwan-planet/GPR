    FILE * fp_r;
    FILE * fp_w;

    fp_r = fopen("/home/changwan/GPR_DATA/KOREA/MIHO_ri/220303.PRJ/HILBERT_BSCAN_STACKED_IMAGE.txt","r");
    
        fp_w = fopen("/home/changwan/GPR_DATA/KOREA/MIHO_ri/pol_dif_output.txt","w");

       //fp_r = fopen("/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/HILBERT_BSCAN_STACKED_IMAGE.txt","r");
       //fp_w = fopen("/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/dB_output.txt","w");


//        fp_r = fopen("/mnt/l/GPR_DATA/KOREA/INBO_ri/220223_4.PRJ/HILBERT_BSCAN_STACKED_IMAGE.txt","r");
//        fp_w = fopen("/mnt/l/GPR_DATA/KOREA/INBO_ri/220223_4.PRJ/dB_output.txt","w");

    if(fp_r==NULL){
                   puts("fail to open a file to read!");
                   return -1;
                  }

    if(fp_w==NULL){
                   puts("fail to open a file to write!");
                   return -1;
                  }

   //for(int i=0;i<x;i++){
   for(int j=0;j<y;j++){
   for(int i=0;i<x;i++){
   
                  fscanf(fp_r, "%lf", &signal[j][i]); 
                   }   
                   }

