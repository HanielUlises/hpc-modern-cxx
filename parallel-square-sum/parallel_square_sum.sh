#!/bin/bash

g++ -O3 -fopenmp parallel_square_sum.cpp -o parallel_square_sum 

start=$(date +%s.%N)

parallel -j+0 ./parallel_square_sum {} :::: data.txt

end=$(date +%s.%N)

echo "Execution time: $(echo "$end - $start" | bc) seconds"
