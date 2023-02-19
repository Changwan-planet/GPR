int state_r, state_w;

int y=yy;
int x=xx;
    
double t;

double signal[y][x];   

//++++++square++++++//
double * sq_temp;
double  sq_signal[yy];
double * sq_matrix;
double sq_matrix2[yy][xx];

//++++++max++++++//
double * max_temp;
double  max_signal[yy];
double  max_matrix;
double max_matrix2[xx];

//++++++dB++++++//
static double dB_str[yy][xx]; //dB. reference to the strongest echo.

