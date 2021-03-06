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


// Greedy strategy. Sort based on finish times for all those customers preferring the same compartment
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N,K; cin >> N >> K;
		map < int, VPI > M;
		int pi, si, fi;
		REP(i,N)
		{
			scanf("%d%d%d", &si, &fi, &pi);
			M[pi].pb(mkp(fi,si));
		}

		map < int, VPI > :: iterator it = M.begin();
		int ans = 0;
		for(;it!= M.end(); ++it)
		{
			VPI cur = it->second;
			if(cur.sz == 1)
			{
				ans++;
				continue;
			}
			else
			{
				sort(all(cur));
				int cur_f = cur[0].first;
				ans++;
				FOR(i,1,cur.sz)
				{
					if(cur[i].second >= cur_f)
					{
						ans++;
						cur_f = cur[i].first;
					}
				}
			}
		}

		printf("%d\n", ans);

	}

	return 0;
}
