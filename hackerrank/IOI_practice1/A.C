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
	int N,P; cin >> N >> P;

	int grid[N][N];
	REP(i, N) REP(j, N) grid[i][j] = 0;

	
	LL ans = 0;
	REP(i, P)
	{
		string s; int x; int c;
		cin >> s >> x >> c;
		if(s[0] == 'R') REP(k, N) grid[x-1][k] = c;
		else if(s[0] == 'C') REP(k, N) grid[k][x-1] = c;
	}

	REP(i, N) REP(j, N) ans += grid[i][j];

	cout << ans << endl;
	
	return 0;
}
