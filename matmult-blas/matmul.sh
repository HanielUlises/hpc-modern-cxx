#!/bin/bash

CXX=g++
CXXFLAGS=-Ofast
EXTRA_FLAGS="-DLITE_ARRAY_NO_HINT -DNDEBUG"

OPENBLAS_INCLUDE="/usr/include/openblas"
OPENBLAS_LIB="/usr/lib"

SOURCE_FILE="matmul.cpp"
OUTPUT_FILE="matmul"

$CXX $CXXFLAGS -pg $EXTRA_FLAGS $SOURCE_FILE -L$OPENBLAS_LIB -lopenblas -o $OUTPUT_FILE 

./$OUTPUT_FILE > data.txt

gprof ./$OUTPUT_FILE gmon.out > profile_report.txt
