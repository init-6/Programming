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

int dp[302][302][10];

int main()
{
	int N;scanf("%d", &N);
	int inp;

	REP(i,N) REP(j,N) 
	{
		scanf("%d", &inp);
		REP(xx,10)
		dp[i+1][j+1][xx] = dp[i][j][xx] + (dp[i][j+1][xx] - dp[i][j][xx]) + (dp[i+1][j][xx] - dp[i][j][xx]);

		dp[i+1][j+1][inp-1]++;

	}
	
	int Q;scanf("%d", &Q);

	while(Q--)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
		
		int ans[10] = {0};
		REP(i,10)
		{
			ans[i] += dp[x1-1][y1-1][i];
			ans[i] -= dp[x1-1][y2][i];
			ans[i] -= dp[x2][y1-1][i];
			ans[i] += dp[x2][y2][i];
		}

		int cnt = 0;
		REP(i,10) if(ans[i] > 0) cnt++;
		printf("%d\n", cnt);

	}

	return 0;
}
