
    int state_r, state_w;

    int y=4096;
    int x=101;
    double t;

    double signal[y][x];
    double signal_sq[x];
    double dB_str[y][x]; //dB. reference to the strongest echo.
    double max[x];
    double *sum_matrix;
    double (*sq_matrix)[x];