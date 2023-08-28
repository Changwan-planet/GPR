#! /bin/bash

path=/home/changwan/MODULE
 
gfortran -g -mcmodel=medium CSCAN_POL_powerdB.f90\
                            $path/MD_BASIC.f90\
                            -o test_POL
 
 

