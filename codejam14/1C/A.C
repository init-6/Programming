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

LL toint(string s)
{
	stringstream ss;

	LL ret;
	ss << s;
	ss >> ret;
	return ret;
}

PI add(int a, int b, int c, int d)
{
	int num = 2*(a*d + b*c);
	int den = b*d;
	PI ret = mkp(num, den);
	return ret;
}

map < PI, bool> seen;

int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		// Begin code
		int ans = 0;
		string f = "/";
		PI x;
		LL x1, x2;
		string s; cin >> s;
		string s1, s2;
		s1 = s.substr(0,s.find(f));
		s2 = s.substr(s.find(f)+1);
		//cout << s1 << " " << s2 << endl;

		x1 = toint(s1); x2 = toint(s2);
		x = mkp(x1,x2);
		cout << x1 << " " << x2 << endl;
		PI p1, p2;
		p1 = mkp(0,1); p2 = mkp(1,1);
		seen[p1] = true; seen[p2] = true;
		set < pair <PI, int> > S;
		S.insert(mkp(p1, 1)); S.insert(mkp(p2, 1));

		

		ans = count;
		cout << "Case #" << c+1 << ": " << ans << endl;
	}

	return 0;
}
