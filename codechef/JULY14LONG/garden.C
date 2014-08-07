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

const int MOD = (1e9) + 7;

int N;
set <int> seen;
VI inp;

int dfs(int v)
{
	if(seen.find(v) != seen.end()) return 0;
	seen.insert(v);
	return 1 + dfs(inp[v]-1);
}

LL inv(LL x, LL n)
{
	LL ret = 1;
	while(n)
	{
		if(n&1)
		ret = ((ret % MOD) * (x % MOD)) % MOD;
		ret = ((ret % MOD) * (ret % MOD)) % MOD;
		n >>= 1;
	}

	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> N;
		inp.clear();
		int e;
		REP(i, N) 
		{
			cin >> e;
			inp.pb(e);
		}
		seen.clear();

		LL lcm = 1;

		REP(i, inp.sz)
		{
			if(seen.find(i) == seen.end())
			{
				LL size = dfs(i);
				lcm = ( ( (lcm % MOD) * (size % MOD) ) * (inv(__gcd(lcm, size), MOD-2) % MOD ) ) % MOD;
			}
		}

		cout << lcm << endl;
		
	}
	return 0;
}
