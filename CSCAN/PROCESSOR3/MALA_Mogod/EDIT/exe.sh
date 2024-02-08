#!/bin/bash

path=/home/changwan/MODULE

gfortran -g -mcmodel=medium MALA_GPR_EDIT.f90\
                           $path/MD_BASIC.f90\
                           $path/MD_FFT_IFFT.f90\
                           $path/MD_FFT_HILBERT.f90\
                           $path/p_determination.f90\
                           $path/MD_FILTER.f90\
                           $path/MD_INTERPRE.f90\
                           $path/MD_MEAN_ASCAN.f90\
                           $path/MD_MVMEAN.f90 -o test_MALA




            #                $path/MD_TWMVMEAN.f90\
 
