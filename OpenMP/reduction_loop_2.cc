#include <cstdio>
#include <omp.h>
#include <cmath>

constexpr int N = 1'000'000'000;

int main(void) {
    double calc = 0;
    #pragma omp parallel for reduction(+:calc)
    for(int i = 0; i < N; i++) 
        calc += std::pow(-1, i) * 1.0/(2*i +1);
    printf("%.12f\n", 4 *calc); return 0;
    
    return 0;
}