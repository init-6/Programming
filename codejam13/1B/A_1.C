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
		int S,N;
		cin >> S >> N;
		int motes[N+1];
		FOR(i,1,N+1) cin >> motes[i];

		int inserts = 0;
		int ans = N;
		sort(motes+1, motes+1+N);
		if (S == 1)
		cout << "Case #" << c+1 << ": " << ans << endl;
		else
		{
			FOR(i,1,N+1)
			{
				while(S <= motes[i])
				{
					inserts++;
					S += S-1;
				}
				// absorb now
				S += motes[i];
				ans = min(ans, inserts + (N - i));
			}


			cout << "Case #" << c+1 << ": " << ans << endl;
		}
	}

	return 0;
}
