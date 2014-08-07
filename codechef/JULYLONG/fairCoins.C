#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007

vector <int> dp;

void go()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for(int i=3;i<=1000000000;i++)
	{
		dp[i] = ((2*dp[i-1])%MOD + (2*dp[i-2])%MOD)%MOD;
	}
}
int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		memset(dp,0,sizeof(dp));
		go();
		cout << dp[N] << endl;
	}
}
