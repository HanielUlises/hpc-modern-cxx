#define alpha(i, j) A[(j) * lda + i]
#define beta(i, j)  B[(j) * ldB + i]
#define gamma(i, j) C[(j) * ldC + i]

void my_gemm(int m, int n, int k, double *A, int lda,
                                  double *B, int ldB,
                                  double *C, int ldC) {
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++)
            for(int p; p < k; p++)
                gamma(i, j) += beta(p,j) * alpha(i, p);

} 