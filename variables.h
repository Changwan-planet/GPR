
    int state_r, state_w;

    int y=yy;
    int x=xx;
    
    double t;

    double signal[y][x];
    
    double dB_str[y][x]; //dB. reference to the strongest echo.
    double max[x];

    double *sum_matrix;

    double *sq_temp;

    double sq_signal[y];

    double **sq_matrix;
   

