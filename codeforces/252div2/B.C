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
	int n, lim;
	cin >> n >> lim;
	VPI d(n);
	REP(i, n)
	{
		int x; int f;
		cin >> x >> f;
		d[i] = (mkp(x, f));
	}

	sort(all(d));
	int ret = 0;
	REP(i, d.sz - 1)
	{
		if(d[i].first == d[i+1].first-1)
		{
			if(d[i].second >= lim && d[i+1].second >= lim)
			{
				ret += lim+lim;
				d[i+1].second -= lim;
				d[i].second = 0;
			}
			else if(d[i].second + d[i+1].second < lim)
			{
				ret += d[i].second + d[i+1].second;
				d[i].second = d[i+1].second = 0;
			}
			cout << ret << endl;
		}
		else
		{
			if(d[i].second >= lim)
			ret += lim;
			else
			ret += d[i].second;
		}
	}

	if(d[d.sz-1].second >= lim)
	ret += lim;

	cout << ret << endl;
	return 0;
}
