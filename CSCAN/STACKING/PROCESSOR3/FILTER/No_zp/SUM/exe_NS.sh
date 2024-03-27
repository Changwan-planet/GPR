#!/bin/bash
path=/mnt/c/Users/KIGAM/Desktop/MODULE
#path=/home/changwan/MODULE

gfortran -g -mcmodel=medium CSCAN_GPR_NS.f90\
                           $path/MD_BASIC.f90\
                           $path/MD_FFT_IFFT.f90\
                           $path/MD_FFT_HILBERT.f90\
                           $path/p_determination.f90\
                           $path/MD_FILTER.f90\
                           $path/MD_INTERPRE.f90\
                           $path/MD_MEAN_ASCAN.f90\
                           $path/MD_MVMEAN.f90 -o test_NS




            #                $path/MD_TWMVMEAN.f90\
 