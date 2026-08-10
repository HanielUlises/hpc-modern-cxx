#include <stdio.h>
#include <omp.h>



int main() {
    double sum = 0;
    #pragma omp parallel 
    {
    int id = omp_get_thread_num();
        #pragma omp critical
        sum += work(id);
    }
   
}