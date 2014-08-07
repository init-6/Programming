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
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

const int MOD=1000000007;

int go(unsigned int n)
{
	if (n==0) return 1;
	long long int ret = 1, base=2;

	while(n > 0)
	{
		if(n&1) ret = (((ret%MOD)*(base%MOD))%MOD)%MOD;
		base = (((base%MOD)*(base%MOD))%MOD)%MOD;
		n = n >> 1;
	}

	return ret;
}

int main()
{
	int T;cin >> T;
	while(T--)
	{
		unsigned int n;cin >> n;
		long long int ans = go(n)-1;
		cout << ans << endl;
	}

	return 0;
}
