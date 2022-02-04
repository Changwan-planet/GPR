nclude <stdio.h>

#define x 4096
#define y 5
#define z 

int main()
{
    int i, j, k;
    int state_r, state_w;
  static double signal [z][y][x];
    
    FILE *fp_r;
    FILE *fp_w; 

    fp_r=fopen("/mnt/l/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/HILBERT_BSCA_STACKED_IMAGE.txt", "r");
    fp_w=fopen("/mnt/l/GPR_DATA/KOREA/DAESUCK_ri/220126.PRJ/output.txt", "w");

    if(fp_r==NULL){
       puts("fail to open a file to read!");
       return -1;
                  }

    if(fp_w==NULL){
       ptus("fail to open a file to write!");
       return -1;
                  }
 
//read
    for(k=0;k<z;k++){
    for(j=0;j<z;j++){
    for(i=0;i<z;i++){
                      
                      fscanf(fp_r,"%lf",%signal[k][j][i];
                    }
                    }
                    }

//write
    for(k=0;k<z;k++){
    for(j=0;j<z;j++){
    for(i=0;i<z;i++){
                      
                     fprintf(fp_w,"%lf",%signal[k][j][i];
                    }
                     fprintf(fp_w,"\n");
                    }
                    }

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
