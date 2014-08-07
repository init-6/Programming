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
#define INF 500
typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int adj[111][111];

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int n,m;cin >> n >> m;
		int degree[n+1];
		CLEAR(degree, 0);
		int v1,v2;

		REP(i,m)
		{
			cin >> v1 >> v2;
			if(v1 != v2 && adj[v1][v2] == 0 && adj[v2][v1] == 0)
			{
				adj[v1][v2] = adj[v2][v1] = 1;
				degree[v1]++;degree[v2]++;
			}
		}

		FOR(i,1,n+1)
		{
			FOR(j,1,n+1)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}

		REP(i,n) cout << degree[i+1] << " ";
		cout << endl;

		int start = INF, cur_deg = INF;
		FOR(i,2,n+1)
		{
			if(adj[1][i] == 1 && degree[i] < cur_deg)
			{
				start = i;
				cur_deg = degree[i];
			}
		}
		cout << start << endl;

		FOR(i,1,n+1)
		{
			bool one_found = false;
			FOR(j,1,n+1)
			{
				if(one_found)
				{
					adj[i][j] = 0;
				//	cout << "Found another 1 at " << "(" << i << " , " << j << ")" << endl;
					continue;
				}
				if( i == 1)
				{
					if(j != start)
						adj[i][j] = 0;
				}
				else
				{
					if(i > j)
					{
						if(adj[i][j] == 1 && adj[j][i] == 0)
						{
							adj[i][j] = 0;
						}
						else if(adj[i][j] == 1)
						{
							// found a one in the row so clear other ones.
							one_found = true;
						}
					}
					if(j > i && adj[i][j] == 1)
					{
						one_found = true;
						continue;
					}

				}
			}
		}

			FOR(i,1,n+1)
			{
				FOR(j,1,n+1)
				{
					cout << adj[i][j] << " ";
				}
				cout << endl;
			}

		int cnt[n+1];
		CLEAR(cnt,0);
		FOR(i,1,n+1)
		{
			FOR(j,1,n+1)
			{
				if(adj[i][j] == 1) cnt[i]++;
			}
		}

		bool good  = true;
		REP(i,n)
		{
			good = good && (cnt[i+1] == 1);
		}

		if(good) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}
