#!/bin/bash 

> execution_time.txt

run_and_time() {
    optimization_name=$1
    executable=$2

    real_time=$( { time ./$executable; } 2>&1 | grep real | awk '{print $2}' )
    echo "$optimization_name : $real_time"
    echo "$optimization_name : $real_time" >> execution_time.txt
}

gcc -O0 matrix_multiplication.c -o matrix_multiplication
run_and_time "Baseline (no optimization)" "matrix_multiplication"

gcc -O3 -floop-interchange matrix_multiplication.c -o matrix_loop_interchange
run_and_time "Loop Interchange" "matrix_loop_interchange"

gcc -O3 -floop-block matrix_multiplication.c -o matrix_loop_tiling
run_and_time "Loop Tiling" "matrix_loop_tiling"

gcc -O3 -ftree-vectorize matrix_multiplication.c -o matrix_vectorized
run_and_time "Loop Vectorization" "matrix_vectorized"

gcc -O3 -fopenmp matrix_multiplication.c -o matrix_openmp
run_and_time "OpenMP Parallelization" "matrix_openmp"
