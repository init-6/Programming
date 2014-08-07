#include <vector>
#include <queue>
#include <climits>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

const int MAXN = 1e5+1;
const int MOD = 1e9 + 7;

int fibo[26];
int dp[26][MAXN];
VI a;

void fib()
{
	fibo[0] = 1; fibo[1] = 1;
	FOR(i, 2, 26) fibo[i] = fibo[i-1]+fibo[i-2];
}

int solve(int i, int num)
{
	if(dp[i][num] != 0)
	return dp[i][num];

	if(num == 0)
	return 1;	

	if(num < 0)
	return 0;

	if (i <= 0 && num >= 1)
	return 0;
	else 
	{
		dp[i][num] = ((solve(i, num-a[i-1]) % MOD ) + (solve(i-1, num) % MOD) ) % MOD;
		return dp[i][num];	
	}	
}

int main()
{
	fib();
	int T; cin >> T;
	while(T--)
	{
		a.clear();
		int N; cin >> N;
		int K; cin >> K;


		FOR(i,1,26)
		{
			if(fibo[i] > N)
				break;

			if(N >= fibo[i] && fibo[i] != K)
				a.pb(fibo[i]);
		}

		int m = a.sz;

		REP(i,m+1)
			REP(j,N+1)
			dp[i][j] = 0;


		int ans = solve(m, N);

		//REP(i,m)
		//dp[0][i] = 1;

		//REP(i, m)
		//{
		//	for(int j = a[i]; j<=N; j++)
		//	dp[j] = ((dp[j]%MOD) + (dp[j-a[i]]%MOD)) % MOD;
		//}

		//FOR(i,1,N+1)
		//{
		//	REP(j,m)
		//	{
		//		int with = (i-a[j] >= 0)? dp[i - a[j]][j]: 0;
		//		int without = (j >= 1)? dp[i][j-1]: 0;
		//		dp[i][j] = ((with%MOD) + (without%MOD)) % MOD;
		//	}
		//}

		cout << ans << endl;

	}

	return 0;
}
