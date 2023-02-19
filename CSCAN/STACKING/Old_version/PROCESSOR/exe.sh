#!/bin/bash

path=/home/changwan/MODULE
#path=/mnt/l/MODULE


gfortran -g -mcmodel=medium CSCAN_GPR_NS.f90 $path/MD_MEAN_ASCAN.f90\
                       $path/MD_BASIC.f90\
                       $path/MD_FFT_IFFT.f90\
                       $path/MD_FFT_HILBERT.f90\
                       $path/p_determination.f90 -o test

