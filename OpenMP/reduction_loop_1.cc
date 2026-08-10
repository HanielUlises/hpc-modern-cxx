#include <cstdio>
#include <omp.h>

int main(void) {
    #pragma omp parallel for collapse(2)
    for(int x = -1; x <= 1; x++) 
        for(int y = - 1; y <=1; y++) 
            printf("Thread %d: (%d, %d)\n", omp_get_thread_num(), x, y);
            
    
    return 0;
}