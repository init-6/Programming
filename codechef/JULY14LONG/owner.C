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

const int MAX = 2e4 + 10;

int color[MAX], inp[MAX];

void _disjointInit(int N)
{
	FOR(i, 1, N+1) color[i] = i;
}

int getcolor(int x) // Find the color of the representative of the disjoin set
{
	return color[x] = (color[x] == x ? x : getcolor(color[x]);// Path compression
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);;
		_disjointInit(N);
		FOR(i, 1, N+1) scanf("%d", &inp[i]);
		int Q; scanf("%d", &Q);;
		REP(i, Q)
		{
			int code;
			scanf("%d", &code);
			if(!code) // query for update
			{
				int u, v; scanf("%d%d", &u, &v);
				int col_u = getcolor(u);
				int col_v = getcolor(v);
				if(col_v == col_u)
				printf("Invalid query!\n");
				else if(inp[col_v] > inp[col_u])
				color[col_u] = col_v;
				else if(inp[col_v] < inp[col_u])
				color[col_v] = col_u;
			}
			else // Query to print the owner
			{
				int u; scanf("%d", &u);
				printf("%d\n", getcolor(u));
			}
		}
	}

	return 0;
}
