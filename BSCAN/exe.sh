#!/bin/bash

#path=/home/changwan/MODULE

path=/mnt/l/MODULE

gfortran -mcmodel=medium -g BSCAN_GPR.f90 $path/MD_BACKGROUND.f90\
                       $path/MD_STACKING.f90\
                       $path/MD_FFT_IFFT.f90\
                       $path/MD_FFT_HILBERT.f90\
                       $path/p_determination.f90 -o test
./test
