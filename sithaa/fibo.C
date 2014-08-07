#include <iostream>

using namespace std;

int main()
{
	cout << "Enter a number" << endl;
	int N;
	cin >> N;
	
	int fibo[N];

	fibo[0] = 0; fibo[1] = 1;
	for(int i=2;i<N;i++)
	fibo[i] = fibo[i-1] + fibo[i-2];

	cout << "The " << N << " fibonacci numbers are " << endl;
	for(int i = 0; i < N; i++)
	cout << fibo[i] << " " ;

	cout << endl;
	return 0;
}
