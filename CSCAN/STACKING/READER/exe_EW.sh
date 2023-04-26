#!/bin/bash

path=/home/changwan/MODULE
#path=/mnt/l/MODULE

gfortran -g -mcmodel=medium CSCAN_GPR_EW_reader.f90 \
                       $path/MD_BASIC.f90\
                       $path/MD_STACKING.f90 -o test_EW

