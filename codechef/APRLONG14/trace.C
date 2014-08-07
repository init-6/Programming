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

LL go(int d)
{
	int root = sqrt(d);
	LL ret = 0;
	FOR(i,1,root+1)
	ret += (2*(d/i - i) + 1);

	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);

		LL ans = 0;
		FOR(k,1,N/2+1)
		{
			if(k == N-k)
			ans += go(k*(N-k) - 1);
			else
			ans += 2*go(k*(N-k)-1);
		}

		printf("%lld\n", ans);

	}
	return 0;
}
