#include <iostream>
#include <vector>

using namespace std;

const  int MODU=1000000007;


int dp[1000002];

void go()
{
	dp[0] = 1; dp[1] = 2;
	for( int i=2;i<1000002;i++)
		dp[i] = ((dp[i-1] % MODU) + (dp[i-2]%MODU)) % MODU;
}


int count( int N)
{
	int res = 0;
	while(N)
	{
		N &= N-1;
		res++;
	}
	return res;
}

int main()
{
	int T;cin >> T;
	go();
	while(T--)
	{
		int n,G;
		cin >> n >> G;

		int cnt = count(dp[n-1]);
		cout << dp[n-1] << endl;

		cnt == G ? cout << "CORRECT" << endl : cout << "INCORRECT" << endl;

	}

	return 0;
}
