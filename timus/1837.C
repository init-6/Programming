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
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	int N;cin >> N;
	vector <int> adj[300];
	map <string, int> id;
	
	int V=0;
	REP(i,N)
	{
		string root,c1,c2;cin >> root >> c1 >> c2;
		if(id.find(root) == id.end())
		id[root] = V++;
		if(id.find(c1) == id.end())
		id[c1] = V++; 
		if(id.find(c2) == id.end())
		id[c2] = V++;
		adj[id[root]].pb(id[c1]);adj[id[root]].pb(id[c2]);	
		adj[id[c1]].pb(id[root]);adj[id[c1]].pb(id[c2]);	
		adj[id[c2]].pb(id[root]);adj[id[c2]].pb(id[c1]);	
	}

	int dist[300];
	memset(dist,-1,sizeof(dist));
	if(id.find("Isenbaev") != id.end())
	{
		dist[id["Isenbaev"]] = 0;
		queue <int> Q;
		Q.push(id["Isenbaev"]);
		//EACH(it,id)
		//cout << it->first << " " << it->second << endl;
	
		while(!Q.empty())
		{
			int cur_v = Q.front();
			//cout << cur_v << endl;
			Q.pop();
			REP(i,adj[cur_v].sz)
			{
				//cout << "adj of " << cur_v << " is " << adj[cur_v][i] << endl;
				//cout << dist[adj[cur_v][i]] << " is the distance of " << adj[cur_v][i] << " from source" << endl; 
				if(dist[adj[cur_v][i]] == -1)
				{
					dist[adj[cur_v][i]] = dist[cur_v]+1;
					Q.push(adj[cur_v][i]);
				}
			}
		}
	}
	EACH(it,id)
	{
		if(dist[it->second] == -1)
		cout << it->first << " " << "undefined" << endl;
		else
		cout << it->first << " " << dist[it->second] << endl;
	}

	return 0;
}
