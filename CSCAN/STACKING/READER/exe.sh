#!/bin/bash

path=/home/changwan/MODULE
#path=/mnt/l/MODULE


gfortran -g -mcmodel=medium CSCAN_GPR_NS.f90 $path/MD_BACKGROUND.f90\
                       $path/MD_STACKING.f90 -o test

