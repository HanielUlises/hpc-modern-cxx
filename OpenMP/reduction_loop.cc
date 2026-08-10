#include <cstdio>
#include <omp.h>

int main(void) {
    #pragma omp parallel for 
    for(int i = 0; i < 4 * omp_get_num_threads(); i++) 
        printf("Thread %d, i = %d\n", omp_get_thread_num(), i);
    
    return 0;
}