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
	int N;
	while(cin >> N)
	{
		bitset<32> bits(N);

		string s = bits.to_string();
		string ans;

		for(int i=0; i<s.sz; i+=8)
		{
			string byte;
			FOR(k, i, i+8)
			byte += s[k];
			ans = byte+ans;
		}

		bool neg = false;
		if(ans[0] == 1)
		neg = true, ans[0] = 0;
		bitset<32> rbits(ans);

		int res = rbits.to_ulong();
		if(neg) res = -res;

		cout << N << " converts to " << res << endl;
	}

	return 0;
}
