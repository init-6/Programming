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

// DFS based solution to find connected components
bool visited[30];
vector < VI > adj(30);

void dfs(int node)
{
	visited[node] = true;
	//cout << "Hello" << endl;
	REP(i, adj[node].sz)
	if(!visited[adj[node][i]])
	dfs(adj[node][i]);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string num_node;
		cin >> num_node;
		cin.ignore();
		int n = num_node[0] - 'A' + 1;
		//adj.assign(n, VI());
		//adj.clear();
		REP(i, n+1)
		adj[i].clear();
		REP(i, n+1)
		visited[i] = false;
		string edge;
		while(1)
		{
			getline(cin, edge);
			if(edge[0] >= 'A' && edge[0] <= 'Z')
			{
				//cout << edge << endl;
				adj[edge[0] - 'A' + 1].pb(edge[1] - 'A' + 1);
				adj[edge[1] - 'A' + 1].pb(edge[0] - 'A' + 1);
			}
			else break;
		}

		/*	
		FOR(i, 1, adj.sz)
		{
			cout << "Adjacency list of " << i << " is ";
			REP(j, adj[i].sz)
			cout << adj[i][j] << " ";
			cout << endl;
		}
		*/
		int ans = 0;
		FOR(i, 1, n+1)
		{
			if(!visited[i])
			dfs(i), ans++;
		}
		cout << ans << endl;
		if(T) cout << endl;
	}

	return 0;
}
