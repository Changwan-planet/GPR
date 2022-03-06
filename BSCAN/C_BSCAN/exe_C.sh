#!/bin/bash

#path=/mnt/l/GPR
path=/home/changwan/GPR/BSCAN/C_BSCAN

gcc -g GPR_bscan_stat.c $path/basic_math2.c -lm -o test 


#gcc GPR_bscan_stat.c -o test -lm
 
