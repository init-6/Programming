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

vector < pair < int , char > > v;
const int MOD= 1e9 + 7;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int m,n,yi,xi;

		scanf("%d %d",&m,&n);

		int k;
		REP(i,m-1)
		{
			scanf("%d",&k);
			v.pb(mkp(k,'X'));
		}
		REP(i,n-1)
		{
			scanf("%d",&k);
			v.pb(mkp(k,'Y'));
		}

		sort(all(v));
		reverse(all(v));

		yi=xi=1;
		int cost=0;

		REP(i,v.sz)
		{
			if(v[i].second == 'Y')
			{
				cost+=((v[i].first%MOD)*(yi%MOD))%MOD;
				xi++;
			}
			else
			{
				cost+=((v[i].first%MOD)*(xi%MOD)%MOD);
				yi++;
			}
		}

		printf("%d\n",cost);
		v.erase(v.begin(),v.end());
	}
	return 0;
} 


