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

const LL MOD = (1e9) + 9;

LL C[10001];

LL go(int N)
{
	if(C[N] != -1) return C[N];
	LL ret = 0;
	if(N == 0) ret = 1;
	FOR(i, 1, N+1)
	ret = ((ret % MOD) + ((go(i-1) % MOD)*(go(N-i) % MOD) % MOD)) % MOD;

	return C[N] = ret;
}

int main()
{
	int T; cin >> T;
	memset(C, -1, sizeof(C));
	while(T--)
	{
		int N; cin >> N;
		LL t = (3 * N - 2);
		LL ans = ((t % MOD) * (go(N-1) % MOD)) % MOD;
		cout << ans << endl;
	}

	return 0;
}
