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
	int N, M; cin >> N >> M;
	vector < pair < int, pair <bool, int> > > r;
	int a, b, k;
	REP(i, M)
	{
		cin >> a >> b >> k;
		r.pb(mkp(a, mkp(false, k)));
		r.pb(mkp(b, mkp(true, k)));
	}

	sort(all(r));

	LL ans = 0, cnt = 0;
	REP(i, r.sz)
	{
		if(!r[i].second.first)
			cnt += r[i].second.second;
		else
			cnt -= r[i].second.second;

		//cout << "cnt : " << cnt << endl;
		ans = max(ans, cnt);
		//cout << "ans : " << ans << endl;
	}

	cout << ans << endl;

	return 0;
}
