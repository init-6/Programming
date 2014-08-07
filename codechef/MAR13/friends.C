#include <vector>
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

const ll MODU = 1000000007;

int color[100005];
int getcolor(int a)
{
	return color[a] == a ? a : getcolor(color[a]);
}

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N, M;cin >> N >> M;
		int f1,f2;
		VPI edges;
		REP(i,M)
		{
			cin >> f1 >> f2;
			edges.pb(mkp(f1,f2));			
		}

		FOR(i,1,N+1) color[i] = i;	

		map <int, int> cnt;

		VPI :: iterator it;
		EACH(it, edges)
		{
			int c1 = getcolor(it->first);
			color[it->second] = c1;
		}

		ll ans = 1;

		FOR(i,1,N+1)
		{
			color[i] = getcolor(color[i]);
		}

		FOR(i,1,N+1)
		{
			cnt[color[i]]++;
		}

		map <int, int> :: iterator mit;
		for(mit= cnt.begin();mit!=cnt.end();++mit)
		{
			ans = ((ans % MODU) * ((mit->second)%MODU)) % MODU;
		}

		cout << cnt.sz  << " " << ans << endl;


	}
	return 0;
}
