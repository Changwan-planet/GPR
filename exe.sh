#!/bin/bash

path=/mnt/l/GPR
#path=/home/changwan/GPR

gcc -g -lm GPR_bscan_stat.c $path/basic_math.c -o test 
#gcc GPR_bscan_stat.c -o test -lm
 
