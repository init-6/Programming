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


struct sort_second
{
	bool operator() (const PI &a, const PI &b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int N;cin >> N;
	VPI data(N);
	REP(i,N)
	{
		int St, Ft;
		cin >> St >> Ft;
		data[i] = mkp(St,Ft);
	}

	sort(all(data), sort_second());

	int ans = 0;
	int cur_ft = 0;
	REP(i,N)
	{
		if(data[i].first > cur_ft)
		{
			cur_ft = data[i].second;
			ans++;
		}
	}
	//REP(i,N)
	//cout << data[i].first << " " << data[i].second << "\n";

	cout << ans << endl;
	return 0;
}
