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
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

ULL memo[5000001];

ULL go(ULL n)
{
	if(n < 5000000)
	{
		if(memo[n]) return memo[n];
		if(n & 1) return memo[n] = 2 + go((3*n+1)>>1);
		else return memo[n] = 1 + go(n >> 1);
	}
	if(n & 1)
	return 2 + go((3*n+1)>>1);
	
	return 1 + go(n >> 1);
}

ULL dp[5000001];

int main()
{
	ULL l,r;
	l = 1; r = 5000000;

	ULL maxx = 0;
	ULL maxi = 0;

	memo[1] = 1;

	for(ULL i = l; i <= r; ++i)
	{
		ULL cur = go(i);
		if(cur >= maxx)
		{
			maxx = cur;
			maxi = i;
			dp[i] = maxi;
		}
		else
		dp[i] = maxi;
	}

	int T; cin >> T;
	while(T--)
	{
		ULL N; cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}

