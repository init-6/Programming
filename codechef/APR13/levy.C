#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool prime[10005];
int primes[10005];
int j;

void go()
{
	for(int i=0;i<=10004;i++)
	prime[i] = true;
	prime[0] = prime[1] = false;
	int m = sqrt(10005);
	for(int i=2;i <= m; i++)
	{
		if(prime[i])
		for(int j=i*i; j <= 10001; j+=i)
		prime[j] = false;
	}
	for(int i=2;i<=10004;i++)
	{
		if(prime[i])
		primes[j++] = i;
	}
	
}

int main()
{
	int T;cin >> T;
	int N;
	memset(primes,0,sizeof(primes));
	go();
	while(T--)
	{
		cin >> N;

		int ways=0;
		for(int k=0;k < j && primes[k] < N/2;k++)
		{
			if(prime[N-2*primes[k]])
			ways++;
		}

		cout << ways << endl;
	}

	return 0;
}
