#!/bin/bash

path=/home/changwan/MODULE
#path=/mnt/l/MODULE

gfortran -mcmodel=medium FFT_test.f90 $path/MD_FFT_IFFT.f90 $path/p_determination.f90 -o test

