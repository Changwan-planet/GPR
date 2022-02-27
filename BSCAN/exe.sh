#!/bin/bash

path=/home/changwan/MODULE

gfortran -mcmodel=medium BSCAN_GPR.f90 $path/MD_BACKGROUND.f90\
                       $path/MD_STACKING.f90\
                       $path/MD_FFT_IFFT.f90\
                       $path/MD_FFT_HILBERT.f90\
                       $path/p_determination.f90 -o test

