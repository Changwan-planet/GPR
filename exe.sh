#!/bin/bash

path=/mnt/l/GPR
gcc -lm GPR_bscan_stat.c $path/basic_math.c -o test 
#gcc GPR_bscan_stat.c -o test -lm


./test 
