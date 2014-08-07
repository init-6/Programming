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

int y[3000], x[3000], slope[3000];
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);

		REP(i,N)
		scanf("%d%d", x+i, y+i);

		int ans = 1;
		
		REP(i,N)
		{
			int cnt = 1;
			int sidx = 0;
			FOR(j, i+1, N)
			{
				int dx = x[i] - x[j];
				if(dx == 0)
				cnt++;
				else
				slope[sidx++] = ((y[i] - y[j]) << 20) / dx;
			}

			ans = max(ans, cnt);

			sort(slope, slope+sidx);
			// count the equal slopes
			int eq = 2;
			REP(k, sidx-1)
			{
				if(slope[k] == slope[k+1])
				eq++;
				else eq = 2;

				ans = max(eq, ans);
			}
			ans = max(eq, ans);
		}

		printf("%d\n", ans-1);
	}
	
	return 0;
}
