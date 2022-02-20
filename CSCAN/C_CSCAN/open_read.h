    FILE *fp_r;
    FILE *fp_w; 

    //fp_r=fopen("/mnt/l/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/HILBERT_BSCA_STACKED_IMAGE.txt", "r");
    //fp_w=fopen("/mnt/l/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/output.txt", "w");
    //fp_r=fopen("/home/changwan/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/HILBERT_BSCA_STACKED_IMAGE.txt", "r");
    //fp_w=fopen("/home/changwan/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/output.txt", "w");

//KOREA 
    fp_r=fopen("/home/changwan/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/test.txt", "r");
   
    //fp_r=fopen("/home/changwan/GPR_DATA/KOREA/211028/HILBERT_3D_CUBE_IMAGE_GPR.txt", "r");
    fp_w=fopen("/home/changwan/GPR/CSCAN/C_CSCAN/output.txt", "w");

//MOGOD    
    //fp_r=fopen("/home/changwan/GPR_DATA/MOGOD/2021/F2/800MHz", "r");
    //fp_w=fopen("/home/changwan/GPR/CSCAN/C_CSCAN/output.txt", "w");


    if(fp_r==NULL){
       puts("fail to open a file to read!");
       return -1;
                  }

    if(fp_w==NULL){
       puts("fail to open a file to write!");
       return -1;
                  }
 
//read
    //for(int k=0; k<z; k++){
    //for(int j=0; j<y; j++){
    //for(int i=0; i<x; i++){ 

    for(int i=0; i<xx; i++){
    for(int j=0; j<yy; j++){                   
    for(int k=0; k<zz; k++){

            fscanf(fp_r,"%lf",&signal[k][j][i]);
                          }
                          }
                          }


