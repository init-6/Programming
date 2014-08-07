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
#define dbg(s) cout << s << endl
typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;


const double add = sqrt(20000);
const double dist = 100.0;
int main()
{
	int N,M; 
	//while(cin >> M >> N)
	//{
	cin >> M >> N;

	int d; cin >> d;

	bool good[1001][1001];
	REP(i,1001) REP(j,1001) good[i][j] = false;

	float dp[1001][1001];
	REP(i,1001) REP(j,1001) dp[i][j] = 0.0;
	
	dp[0][0] = 0;

	REP(i,d)
	{
		int x,y; cin >> x >> y;
		good[x][y] = true;
	}

	FOR(i,1,M+1)
	dp[i][0] = dist + dp[i-1][0];

	FOR(i,1,N+1)
	dp[0][i] = dist + dp[0][i-1];

	FOR(i,1,M+1)
	{
		FOR(j,1,N+1)
		{
			if(good[i][j])
			dp[i][j] = add + dp[i-1][j-1];
			else
			dp[i][j] = dist + min(dp[i-1][j], dp[i][j-1]);
		}
	}
//	FOR(i,0,M+1)
//	{
//		FOR(j,0,N+1)
//		cout << dp[i][j] << " ";
//		cout << endl;
//	}

	cout << round(dp[M][N]) << endl;
	//}
	
	return 0;
}
