
#include <iostream>
using namespace std;


void matmul(int N, const double* A, const double* B, double* C) {
	int i, j, k;
	double temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			temp = 0;
			for (k = 0; k < N; k++) {
				C[i*N+j] += A[i*N+k]*B[k*N+j];
			}
			//C[i*N+j] = temp;
		}
		
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << C[i*3 + j ] << " ";
		}
		cout << endl;
	}
}

int main()
{
	double* A, *B, *C;
	// Specifying base addresses for i/p matrices and o/p matrix;
	A = new double [3*3];
	B = new double [3*3];
	// When i remove the following line. i get segmentation fault(might be the reason for the FAIL of "make -c"
	C = new double [3*3];
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
		// assigning some value to A and B
			A[i*3 + j ] = (double) (i+j) + 1.5;
			B[i*3 + j ] = (double) (i*j) + 2.5;
		}
	}
// printing A : DEBUGGING purposes
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << A[i*3 + j ] << " ";
		}
		cout << endl;
	}
// printing B : DEBUGGING purposes
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << B[i*3 + j ] << " ";
		}
		cout << endl;
	}
// Calling your function	
	matmul(3,A,B,C);
	return 0;	
}


