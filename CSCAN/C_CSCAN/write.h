
//A_SCAN
    
    int i = 1;
    int j = 1;
    sg_temp = &signal[0][j][i];

    for(int k=0; k<zz; k++){
                                           
                       A_signal[k] = *sg_temp;
                       
                       //printf("%lf\n", A_signal[k]);

                       fprintf(fp_w,"%lf\n", A_signal[k]);
                       
                       sg_temp = sg_temp + (xx * yy);
                       }

                       
/*                       
//CSCAN-2D side
    //for(int k=0; k<zz; k++){
    int k = 1000;
    for(int j=0; j<yy; j++){
    for(int i=0; i<xx; i++){
                      
                       fprintf(fp_w,"%lf ",signal[k][j][i]);
                           }
                       fprintf(fp_w,"\n");
                           }

*/

/*                           
//3D cude
    for(int k=0; k<zz; k++){
    for(int j=0; j<yy; j++){
    for(int i=0; i<xx; i++){
                      
                       fprintf(fp_w,"%lf",signal[k][j][i]);
                           }
                       fprintf(fp_w,"\n");
                           }
                           }
*/
