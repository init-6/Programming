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

int lcm(int a, int b)
{
	return (a*b)/ (__gcd(a,b));
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		VI inp(N+2,0);
		inp[0] = inp[N+1] = 1;
		FOR(i, 1, N+1) cin >> inp[i];

		VI ans(N+1, 0);

		REP(i, N+1)
		ans[i] = lcm(inp[i], inp[i+1]);

		REP(i, N+1)
		cout << ans[i] << " ";
		cout << endl;

	}
	return 0;
}
