#include <bits/stdc++.h>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
const int MOD = 1e9 + 7;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;
inline LL fpow(LL n, LL k, int p = MOD) {LL r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

vector <string> graph;

bool ok(int i, int j)
{
	return (i >= 0 && i < graph.sz && j >= 0 && j < graph[0].sz);
}

void dfs(int x, int y)
{
	if(graph[x][y] == '#') return;

	graph[x][y] ='#';
	if(ok(x+1, y)) dfs(x+1, y);
	if(ok(x, y+1)) dfs(x, y+1);
	if(ok(x-1, y)) dfs(x-1, y);
	if(ok(x, y-1)) dfs(x, y-1);

	return;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		graph.clear();
		int N; cin >> N;
		REP(i, N)
		{
			string s; cin >> s;
			graph.pb(s);
		}

		int x, y; cin >> x >> y;
		dfs(x,y);

		REP(i, N) 
		{
			cout << graph[i];
			cout << "\n";
		}
	}
	
	return 0;
}
