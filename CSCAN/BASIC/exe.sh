#!/bin/bash

path=/home/changwan/MODULE

gfortran -g -mcmodel=medium CSCAN_GPR_EW.f90\
                           $path/MD_BASIC.f90\
                           $path/MD_INTERPRE.f90\
                           $path/MD_CROSS_CORRELATION.f90 -o test




            #                $path/MD_TWMVMEAN.f90\
 
