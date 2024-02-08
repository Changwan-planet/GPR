#!/bin/bash
path=/home/csun/MODULE

gfortran -g -mcmodel=medium CSCAN_GPR_EW_reader.f90 $path/MD_BASIC.f90 -o test


