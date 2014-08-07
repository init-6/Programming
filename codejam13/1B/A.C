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
		int A;
		cin >> A;
		int N; cin >> N; 
		multiset <int> sizes;
		int inp;
		REP(i,N) {
			cin >> inp;
			sizes.insert(inp);
		}
		
		int ans = 0;
		multiset <int> :: iterator it = sizes.begin();

		int cnt = 0;
		if(A == 1) 
		ans = N;
		else {
			ans = N;
			while(sizes.size() != 0) {
				if(A > *it)
				{
					A += (*it);
					sizes.erase(it);
					it = sizes.begin();
				}
				else
				{
					while( A-1 + A > *it)
					{
						sizes.insert(A-1);
						cnt++;
						it = sizes.begin();
					}
				}
			}
			if(cnt < ans)
			ans = cnt;
		}


		cout << "Case #" << c+1 << ": "  << ans << endl;
	}

	return 0;
}
