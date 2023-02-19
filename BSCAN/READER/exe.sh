#!/bin/bash
path=/home/changwan/MODULE

gfortran -g -mcmodel=medium BSCAN_GPR_reader.f90 $path/MD_BASIC.f90 -o test

