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
	int N; cin >> N;
	cin.ignore();
	REP(c,N)
	{
		string s;
		std::getline(cin, s);

		if(s == "")
		{
			c--;
			continue;
		}

		string token;
		VI sizes;
		stringstream ss;
		ss << s;
		while(ss>>token)
		sizes.pb(token.sz);

		if(sizes.sz == 0)
		{
			cout << "0" << endl;
			continue;
		}

		int ans = 1, cnt = 1;
		REP(i,sizes.sz-1)
		{
			if(sizes[i] == sizes[i+1])
			cnt++;
			else 
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}

		ans = max(ans, cnt);

		cout << ans << endl;
	}

	return 0;
}
