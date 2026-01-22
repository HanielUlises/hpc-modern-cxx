#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <chrono>
#include <cmath>
#include <ctime>

void tiled_matrix_multiply(double *A, double *B, double *C, int N, int tile_size)
{
    for (int i = 0; i < N * N; ++i) {
        C[i] = 0.0;
    }

    for (int ii = 0; ii < N; ii += tile_size) {
        for (int jj = 0; jj < N; jj += tile_size) {
            for (int kk = 0; kk < N; kk += tile_size) {

                int i_max = (ii + tile_size < N) ? ii + tile_size : N;
                int j_max = (jj + tile_size < N) ? jj + tile_size : N;
                int k_max = (kk + tile_size < N) ? kk + tile_size : N;

                for (int i = ii; i < i_max; ++i) {
                    for (int k = kk; k < k_max; ++k) {
                        double a = A[i * N + k];
                        for (int j = jj; j < j_max; ++j) {
                            C[i * N + j] += a * B[k * N + j];
                        }
                    }
                }
            }
        }
    }
}

void matrix_multiply(double *A, double *B, double *C, int N) {
    for (int i = 0; i < N * N; ++i)
        C[i] = 0.0;

    for (int i = 0; i < N; ++i) {       
        for (int j = 0; j < N; ++j) {   
            for (int k = 0; k < N; ++k) {
                C[i*N + j] += A[i*N + k] * B[k*N + j];
            }
        }
    }
}

void initialize_matrices(double* A, double* B, int M, int N) {
    srand(time(NULL));

    for (int i = 0; i < M * N; i++) {
        A[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    for (int i = 0; i < M * N; i++) {
        B[i] = static_cast<double>(rand()) / RAND_MAX;
    }
}

int main() {
    const int M = 1024, N = 1024;
    double* A = new double[M * N];
    double* B = new double[M * N];
    double* C = new double[M * N];

    initialize_matrices(A, B, M, N);

    auto native_start = std::chrono::high_resolution_clock::now();
    matrix_multiply(A, B, C, N);
    auto native_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> native_elapsed = native_end - native_start;
    std::cout << "Non-tiled execution time: " << native_elapsed.count() << " seconds" << std::endl;
    std::cout << "Verification checksum: " << C[0] + C[M*N-1] << std::endl; 
    std::cout << std::endl;

    const int cache_sizes[] = {64 * 1024, 128 * 1024, 256 * 1024, 1024 * 1024};

    for (size_t i = 0; i < sizeof(cache_sizes) / sizeof(cache_sizes[0]); ++i) {
        int tile_size = static_cast<int>(std::sqrt(cache_sizes[i] / (8 * (2 * M + N))));
        std::cout << "Cache size: " << cache_sizes[i] / 1024 << " KB" << std::endl;
        std::cout << "Tile size: " << tile_size << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        tiled_matrix_multiply(A, B, C, N, tile_size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Tiled execution time: " << elapsed.count() << " seconds" << std::endl;
        std::cout << "Verification checksum: " << C[0] + C[M*N-1] << std::endl; 
        std::cout << std::endl;
    }


    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}