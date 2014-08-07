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
	int T;cin >> T;
	while(T--)
	{
		int n,m;cin >> n >> m;
		int degree[101] = {0};
		int adj[101][101] = {0};
		int v1,v2;
		REP(i,m)
		{
			cin >> v1 >> v2;
			if(adj[v1][v2] == 0 && adj[v2][v1] == 0 && v1 != v2)
			{
				degree[v1]++;degree[v2]++;
				adj[v1][v2] = 1;
				adj[v2][v1] = 1;
			//	cout << v1 << " " << v2 << endl;
			}
		}
		//FOR(i,1,n+1)
		//{
		//	FOR(j,1,n+1)
		//	{
		//		cout << adj[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		if(n%2) 
		{	
			cout << "NO" << endl;
			continue;
		}

		VPI V;
		REP(i,101)
		{
			if(degree[i] > 0)
			{
			//	cout << "Degree of node " << i << " is " << degree[i] << endl;
				V.pb(mkp(degree[i],i));
			}
		}
		sort(all(V));
		REP(i,V.sz)
		{
			cout << "Degree of node " << V[i].second << " is " << V[i].first << endl;
		}
		int seen1[101] = {0};
		int ans1 = 0, ans2 = 0;
		//for (int i=V.sz-1; i >= 0; i--)
		for (int i=0; i < V.sz; i++)
		{
			//cout << V[i].second << " " << V[i].first << endl;
			int a = V[i].second;
			//for(int j = V.sz-1; j >= 0; j--)
			for(int j = 0; j < V.sz; j++)
			{
				int b = V[j].second;
			//	cout << "Has edge " << a << " -> " << b << " ?" << endl;
				if(!seen1[a] && !seen1[b] && (adj[a][b] == 1 || adj[b][a] == 1) )
				{
					ans1 += 2;
					seen1[a] = seen1[b] = 1;
			//		cout << "Yes! Add edge " << a << " -> " << b << endl;
				}
			}
		}

//		int seen2[101] = {0};
//		for (int i=0; i < V.sz; i++)
//		{
//			//cout << V[i].second << " " << V[i].first << endl;
//			int a = V[i].second;
//			for(int j = V.sz-1; j >= 0; j--)
//			{
//				int b = V[j].second;
//			//	cout << "Has edge " << a << " -> " << b << " ?" << endl;
//				if(!seen2[a] && !seen2[b] && (adj[a][b] == 1 || adj[b][a] == 1) )
//				{
//					ans2 += 2;
//					seen2[a] = seen2[b] = 1;
//			//		cout << "Yes! Add edge " << a << " -> " << b << endl;
//				}
//			}
//		}
//
//		reverse(all(V));
//		int seen3[101] = {0};
//		int ans3 = 0, ans4 = 0;
//		//for (int i=V.sz-1; i >= 0; i--)
//		for (int i=0; i < V.sz; i++)
//		{
//			//cout << V[i].second << " " << V[i].first << endl;
//			int a = V[i].second;
//			for(int j = 0; j < V.sz; j++)
//			{
//				int b = V[j].second;
//			//	cout << "Has edge " << a << " -> " << b << " ?" << endl;
//				if(!seen3[a] && !seen3[b] && (adj[a][b] == 1 || adj[b][a] == 1) )
//				{
//					ans3 += 2;
//					seen3[a] = seen3[b] = 1;
//			//		cout << "Yes! Add edge " << a << " -> " << b << endl;
//				}
//			}
//		}
//
//		int seen4[101] = {0};
//		for (int i=0; i < V.sz; i++)
//		{
//			//cout << V[i].second << " " << V[i].first << endl;
//			int a = V[i].second;
//			for(int j = V.sz-1; j >= 0; j--)
//			{
//				int b = V[j].second;
//			//	cout << "Has edge " << a << " -> " << b << " ?" << endl;
//				if(!seen4[a] && !seen4[b] && (adj[a][b] == 1 || adj[b][a] == 1) )
//				{
//					ans4 += 2;
//					seen4[a] = seen4[b] = 1;
//			//		cout << "Yes! Add edge " << a << " -> " << b << endl;
//				}
//			}
//		}
//
//		(ans1 == n || ans2 == n || ans3 == n || ans4 == n ) ? cout << "YES" << endl : cout << "NO" << endl;
//
		(ans1 == n ) ? cout << "YES" << endl : cout << "NO" << endl;

	}

	return 0;
}
