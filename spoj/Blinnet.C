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

class compare {
	public :
		bool operator() (PI &a, PI &b)
		{
			return a.second >= b.second;
		}
};

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int n;cin >> n; // No of cities;
		vector < vector < pair < int, int > > > nodes(n+1);
		nodes.clear();
		bool visited[n+1];
		CLEAR(visited,0);
		FOR(i,0,n)
		{
			string name;cin >> name;
			int outdegree;cin >> outdegree;
			VPI entry;
			REP(j,outdegree)
			{
				// Edges from i;
				int x,cost;
				cin >> x >> cost;
				entry.pb(mkp(x-1,cost));
			}
			nodes.pb(entry);
		}


		priority_queue < PI , vector<PI>, compare > PQ;
		
		int added = 0;
		int cost = 0;
		
		PQ.push(mkp(0,0));
		while(added != n)
		{
			PI cur = PQ.top();
			while(visited[PQ.top().first])
			PQ.pop();
			cur = PQ.top();
			visited[cur.first] = true;
			added++;
			PQ.pop();
			VPI adj_cur = nodes[cur.first];
			REP(i,adj_cur.sz)
			{
				if(!visited[adj_cur[i].first])
				{
					PQ.push(adj_cur[i]);
				}
			}
			cost += cur.second;
		}

		cout << cost << endl;

	}
	return 0;
}
