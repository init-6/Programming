#include <iostream>

using namespace std;

int factorial(int N)
{
	if(N == 0) return 1;
	return N*factorial(N-1);
}

int main()
{
	cout << "Enter a number" << endl;
	int N; cin >> N;


	cout << factorial(N) << endl;
	return 0;
}
