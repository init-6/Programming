#include <iostream>

using namespace std;

int sumofdigitsToN(int N)
{
	
}

int main()
{
	int sum = 0;
	for(int i=1;i<=100;i++)
	{
	int cur = i;
		while(cur)
		{
			sum += (cur%10);
			cur/=10;
		}
		cout << i << endl;
	}

	cout << sum << endl;

	return 0;
}
