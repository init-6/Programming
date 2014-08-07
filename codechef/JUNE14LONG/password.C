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
	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		//cin >> N;
		VPI rules(N);
		bool seen[1000000+10] = {false};
		REP(i, N)
		{
			char x, y;
			//scanf("%d%d", &x, &y);
			cin >> x >> y;
			rules.pb(mkp(x,y));
		}

		string inp; cin >> inp;

		REP(i, rules.sz)
		{
			REP(idx, inp.sz)
			{
				if(!seen[idx] && inp[idx] == rules[i].first)
				{
					seen[idx] = true;
					inp[idx] = rules[i].second;
				}
			}
		}

		//cout << inp << endl;

		bool onlyzero = true;
		REP(i, inp.sz)
		onlyzero &= ((inp[i] == '0' || inp[i] == '.'));

		bool point = false;
		REP(i, inp.sz) if(inp[i] == '.')
		{
			point = true;
			break;
		}
		if(onlyzero)
		printf("0\n");
		//cout << 0 << endl;
		else
		{
			string ans = "";
			int ii = 0;
			if(inp[ii] == '0')
			while(ii < inp.sz && inp[ii] == '0') ii++;
			int jj = inp.sz - 1;
			if(inp[jj] == '0' && point)
			while(jj > 0 && inp[jj] == '0') jj--;
			ans = inp.substr(ii, (jj - ii + 1));
			if(ans[ans.sz-1] == '.')
			ans = ans.substr(0, ans.sz-1);
			cout << ans << endl;
		}
	}
	return 0;
}
