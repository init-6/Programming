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
	string g[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};
	
	string s;
	while(cin >> s)
	{
		if(s == "BYE")
		break;

		map <string, int> M4;
		map <int, string> M3;

		REP(i,10)
		{
			M3[i] = g[i];
			M4[g[i]] = i;
		}

		string a = s.substr(0, s.find('+'));
		string b = s.substr(s.find('+')+1, s.sz-a.sz-2);

		cout << s;
		string ans="";

		int x=0,y=0;
		for(int i = 0; i < a.sz; i+=3)
		x = 10*x + M4[a.substr(i,3)];
		for(int i = 0; i < b.sz; i+=3)
		y = 10*y + M4[b.substr(i,3)];

		int z = x+y;
		stringstream ss;
		ss << z;
		string sum;
		ss >> sum;

		REP(i,sum.sz)
		ans += M3[sum[i]-'0'];

		cout << ans << endl;

	}
	return 0;
}
