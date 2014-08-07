#include <vector>
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
#define len length()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef pair<int, int> PI;

int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		int N,M;cin >> N >> M;
		int lawn[N][M];
		REP(i,N)
		REP(j,M)
		cin >> lawn[i][j];

		int org[N][M];
		REP(i,N)
		REP(j,M)
		{
			org[i][j] = 100;
		}

		int maxR[N];
		int maxC[M];
		memset(maxR,0,sizeof(maxR));
		memset(maxC,0,sizeof(maxC));
		REP(i,N)
		{
			REP(j,M)
			{
				maxR[i] = max(maxR[i],lawn[i][j]);
				maxC[j] = max(maxC[j],lawn[i][j]);
			}
		}
		
		REP(i,N)
		REP(j,M)
		org[i][j] = maxR[i];

		REP(i,N)
		REP(j,M)
		org[i][j] = min(org[i][j],maxC[j]);

		bool ok=true;
		REP(i,N)
		REP(j,M)
		{
			ok &= (org[i][j] == lawn[i][j]);
		}
		string ans = (ok ? "YES" : "NO");
		cout << "Case #" << c+1 << ": " << ans << endl;
	}

	return 0;
}
