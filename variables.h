    int  i, j, k, t;
    int state_r, state_w;
 
   
    double signal[x][z];
    double signal_sq[z];
    double dB_str[x][z]; //dB. reference to the strongest echo.
    double max[x];
    double* sum_matrix[x];
