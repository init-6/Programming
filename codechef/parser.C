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

using namespace std;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		string s; cin >> s;
		if(s[0] == '>')
		{
			cout << "0" << endl;
			continue;
		}
		int ans = 0;
		stack <char> S;
		//bool flag = false;
		int push = 0;
		REP(i, s.sz)
		{
			if(s[i] == '<')
			{
				S.push(s[i]);
				push++;
			}
			if(s[i] == '>' && !S.empty())
			{
				S.pop();
				if(S.empty())
				ans += (push*2), push = 0;
			}
			else if(s[i] == '>' && S.empty())
			break;
		}
		cout << ans << endl;
	}
	return 0;
}
