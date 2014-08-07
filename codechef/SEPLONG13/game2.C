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
	int T;cin >> T;
	while(T--)
	{
		int r,C;cin >> r >> C;
		vector<string> B;
		string inp;
		REP(i,r)
		{
			cin >> inp;
			B.pb(inp);
		}

		int L[500][500], R[500][500], U[500][500], D[500][500];
		CLEAR(L,0);
		CLEAR(R,0);
		CLEAR(U,0);
		CLEAR(D,0);
		REP(i,r)
		REP(j,C)
		{
			if(B[i][j] == '^')
			{
				int x = j-1;
				while(x >= 0 && B[i][x] != '#' && B[i][x] == '^') L[i][j]++,x--; 
				x = j+1;
				while(x < C && B[i][x] != '#' && B[i][x] == '^') R[i][j]++,x++; 
				x = i-1;
				while(x >= 0 && B[x][j] != '#' && B[x][j] == '^') U[i][j]++,x--; 
				x = i+1;
				while(x < r && B[x][j] != '#' && B[x][j] == '^') D[i][j]++,x++; 
			}
		}

		bool good=false;
		int cnt = 0;
		REP(i,r)
		REP(j,C)
		{
			if(B[i][j] == '^')
			{
				int val = min(L[i][j],min(R[i][j],min(U[i][j],D[i][j])));
				//cout << val << endl;
				if(val >= 2)
				{
					good = true;
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}
