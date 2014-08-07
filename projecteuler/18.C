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
		int N; cin >> N;
		int inp[N+2][N+2];
		memset(inp, 0, sizeof(inp));

		FOR(i, 1, N+1)
		{
			FOR(j, 1, i+1)
			cin >> inp[i][j];
		}

//		REP(i, N+2)
//		{
//			REP(j, N+2)
//			{
//				cout << inp[i][j] << " ";
//			}
//			cout << endl;
//		}


		// DP table
		int dp[N+2][N+2];
		memset(dp, 0, sizeof(dp));

		FOR(i, 1, N+2)
		{
			FOR(j, 1, i+1)
			{
				dp[i][j] = inp[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
			}
		}
//		cout << endl;
//		cout << "Dp Table " << endl;
//
//		REP(i, N+2)
//		{
//			REP(j, N+2)
//			{
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}

		int ans = -1;
		REP(i, N+2)
		ans = max(dp[N+1][i], ans);

		cout << ans << endl;
	}

	return 0;
}
