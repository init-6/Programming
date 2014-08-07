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
		string a, b;
		cin >> a >> b;
		string ans1 = "*"+a+"*";
		string ans2 = "";
		int i1 = 0, i2 = 0;
		int match = 0;
		string ans;
		while(i1 < a.sz && i2 < b.sz)
		{
			if(a[i1] == a[i2])
			match++;
			else break;
			i1++, i2++;
		}
		// "match" characters matched
		int rem = b.sz - i2;
		string e(rem, '<');
		ans2 = e + a.substr(i2) + "*";
		ans = ans1.sz < ans2.sz ? ans1 : ans2;
		cout << ans << endl;
		
	}

	return 0;
}
