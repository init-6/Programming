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

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int n, k; cin >> n >> k;

		VI inp(n, 0);
		VI mod(k, 0);

		REP(i, n) 
		cin >> inp[i];

		LL ans = 0;

		vector <LL> pref(n, 0);
		pref[0] = inp[0];
		FOR(i, 1, n)
		pref[i] = pref[i-1] + inp[i];

		REP(i, n)
		mod[pref[i]%k]++;

		if(mod[0] > 0) mod[0]++;

		if( k == 1 && n == 1)
		ans = 1;
		else
		{
			REP(i, k)
			if(mod[i] > 0)
			ans += mod[i]*(mod[i]-1)/2;
		}

		cout << ans << endl;
	}
	return 0;
}
