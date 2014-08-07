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

string to_bin(LL n)
{
	string ret = "";
	while(n)
	{
		ret += (n%2 == 0) ? '0' : '1';
		n>>=1;
	}

	reverse(all(ret));
	int diff = 32 - ret.sz;
	ret = string(diff, '0') + ret;
	return ret;
}

int main()
{
	int N; scanf("%d", &N);
	vector <LL> inp(N, 0);
	unsigned long long x = 0;
	REP(i, N) 
	{
		scanf("%lld", &inp[i]);
		x ^= inp[i];
	}

	LL ans = 0;

	if(!x)
	{
		cout << ans << endl;
		return 0;
	}

	vector < string > bits;
	REP(i, inp.sz)
	{
		//bitset <32> b(inp[i]);
		//string s; stringstream ss;
		//ss << b; ss >> s;
		string s = to_bin(inp[i]);
		bits.pb(s);
	}

	REP(j, 32)
	{
		int cnt = 0;
		REP(i, bits.sz)
		{
			cnt += (bits[i][j] == '1');
		}
		if(cnt & 1)
		{
			ans += cnt;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}

