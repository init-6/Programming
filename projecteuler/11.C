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

int grid[20][20];

int checkrow()
{
	int ans = -1;
	REP(i, 20)
	{
		int cur;
		REP(j, 20-3)
		{
			cur = 1;
			REP(k, 4)
			cur = cur*grid[i][j+k];
			
			ans = max(ans, cur);
		}
	}

	return ans;
}

int checkcol()
{
	int ans = -1;
	REP(i, 20-3)
	{
		int cur;
		REP(j, 20)
		{	
			cur = 1;
			REP(k, 4)
			cur = cur*grid[i+k][j];
			
			ans = max(ans, cur);
		}
	}

	return ans;
}

int checkfdiag()
{
	int ans = -1;
	REP(i, 20-3)
	{
		int cur;
		REP(j, 20-3)
		{	
			cur = 1;
			REP(k, 4)
			cur = cur*grid[i+k][j+k];
			
			ans = max(ans, cur);
		}
	}

	return ans;
}

int checkrdiag()
{
	int ans = -1;
	FOR(i, 3, 20)
	{
		int cur;
		REP(j, 20-3)
		{	
			cur = 1;
			REP(k, 4)
			cur = cur*grid[i-k][j+k];
			
			ans = max(ans, cur);
		}
	}

	return ans;
}

int main()
{
	REP(i,20) REP(j,20) scanf("%d", &grid[i][j]);

	int ans = -1;

	ans = max(checkrow(), ans);
	ans = max(checkcol(), ans);
	ans = max(checkfdiag(), ans);
	ans = max(checkrdiag(), ans);

	cout << ans << "\n";

	return 0;
}	
