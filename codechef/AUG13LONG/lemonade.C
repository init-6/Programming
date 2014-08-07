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
		int n,m;cin >> n >> m;
		int rooms[m];
		REP(i,m)
		cin >> rooms[i];
		int c;
		vector < vector <int> > S;
		REP(i,n)
		{
			cin >> c;
			vector <int> tmp;
			int l;
			REP(j,c)
			{
				cin >> l;
				tmp.pb(l);
			}
			sort(all(tmp));
			S.pb(tmp);
		}

		int ans = 0;
		REP(i,m)
		{
			if(S[rooms[i]].sz > 0)
			{
				ans += S[rooms[i]][S[rooms[i]].sz-1];
				S[rooms[i]].pop_back();
			}
		}

		cout << ans << endl;
	}
}
