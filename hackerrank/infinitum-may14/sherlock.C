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

const LL MOD = 1e9 + 7;

LL inverse(LL x)
{
	LL ret = 1, exp = MOD-2;
	while(exp)
	{
		if(exp & 1)
		ret = ((ret % MOD) * (x % MOD)) % MOD;
		x = ((x % MOD) * (x % MOD) ) % MOD;
		exp = exp >> 1;
	}

	return ret;
}

LL solve(LL N, LL M)
{
	LL ret = 1;
	for(int i = N + 1; i <= N + M - 1; i++)
	ret = ((ret % MOD) * (i % MOD)) % MOD;

	LL send = 1;

	for(int i = 1; i <= M-1; i++)
	send = ((send % MOD) * (i % MOD)) % MOD;


	ret = ((ret % MOD) * (inverse(send)) % MOD ) % MOD;

	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N, M; cin >> N >> M;
		cout << solve(N, M) << endl;
	}
	return 0;
}
