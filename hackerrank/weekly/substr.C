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

int main()
{
	string n; cin >> n;
	vector <string> prefix, suffix;
	REP(i, n.sz)
	{
		prefix.pb(n.substr(0, i));
		suffix.pb(n.substr(i));
	}
	
	LL ans = 0;
	REP(i, v.sz)
	{
		stringstream ss; LL x;
		ss << v[i];
		ss >> x;
		ans = ((ans % MOD) + (x % MOD))%MOD;
	}

	cout << ans << endl;

	return 0;
}
