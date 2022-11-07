#/bin/bash

path=/home/changwan/MODULE
#path=/mnt/l/MODULE

gfortran -g -mcmodel=medium BSCAN_GPR_processor2.f90 $path/MD_BASIC.f90\
                       $path/MD_BACKGROUND.f90\
                       $path/MD_STACKING.f90\
                       $path/MD_MEAN_ASCAN.f90\
                       $path/p_determination.f90\
                       $path/MD_FILTER.f90\
                       $path/MD_MVMEAN.f90\
                       $path/MD_DFT_IDFT.f90\
                       $path/MD_DFT_HILBERT.f90\
                       $path/MD_FFT_IFFT.f90\
                       $path/MD_FFT_HILBERT.f90 -o test
 
