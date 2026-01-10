#include <immintrin.h> 
#include <iostream>
void vectorizedLoop() {
	float arr[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
	__m256 vec = _mm256_loadu_ps(arr); 
	vec = _mm256_add_ps(vec, vec); 
	_mm256_storeu_ps(arr, vec);  
	for (int i = 0; i < 8; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main() {
	vectorizedLoop();
	return 0;
}