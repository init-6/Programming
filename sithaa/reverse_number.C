#include <iostream>

using namespace std;

int digits[50];
int num_digits = 0;


void armstrong(int N)
{
	int sum = 0;
	for(int i = 0; i< num_digits; i++)
	sum = sum + (digits[i]*digits[i]*digits[i]);
	cout << sum <<  " " << N << endl;
	
	if(sum == N)
	cout << "Yes" << endl;
	else cout << "No " << endl;
}
int main()
{

	cout << "ENter a number" << endl;
	int N; cin >> N;
	int pass = N;

	// For reverse digits.
	while(N > 0)
	{
		digits[num_digits] = N%10;
		num_digits++;
		N = N/10;
	}
	// comment the below for armstrong
	//for(int i = 0; i<num_digits; i++)
	//cout << digits[i];
	//cout << endl;


	//Armstrong begins here
	armstrong(pass);
	return 0;
}
