#include <iostream>

using namespace std;

const int MOD = 1000000007;

int exp(unsigned long long int base, unsigned int exponent)
{
	long long int res = 1;
	while(exponent > 0)
	{
		if(exponent % 2)
		res = (res*base)%MOD;
		exponent >>= 1;
		base = (base*base)%MOD;
	}
	return res;
}

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		int exponent;
		if(N%2)
			exponent = (N+3)/2;
		else exponent = N/2;
		long long int ans = exp(2,exponent);
		if(N%2)
		cout << ans - 2 << endl;
		else cout << ((3*ans) % MOD) - 2 << endl;
	}

	return 0;
}
