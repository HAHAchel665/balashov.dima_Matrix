#include<iostream>

int ** CreateMatrix(size_t m, size_t n);

void DeleteArray(int** t, size_t m, size_t n);

int main()
{
	size_t M=0, N=0;
	std::cin >>M>>N;
	int **t = ct (M,N);
	std::cout << M << " " << N << "/n";
}
