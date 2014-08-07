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
typedef pair <LL, LL> PLL;

int main()
{
	int N; cin >> N;
	vector < pair < LL, LL > > data;
	LL ti, li;
	REP(i, N)
	{
		cin >> ti >> li;
		data.pb(mkp(ti, li));
	}
	sort(all(data));

	priority_queue < PLL, vector < PLL >, greater < PLL > > Q;
	
	int last = -1, i = 0;
	LL t = 0,wait = 0;

	do
	{
		for(i = last+1; i < N && data[i].first <= t; i++)
		Q.push(mkp(data[i].second, data[i].first));

		last = i-1; // Update the window starting point for next iteration
		if(Q.empty())
		{
			t = data[i].first;
			last++;
			Q.push(mkp(data[i].second, data[i].first));
		}
		wait += (t + Q.top().first - Q.top().second);
		t += Q.top().first;
		Q.pop();
	}
	while(!Q.empty() || last < N-1);


	cout << wait/N << endl;
	return 0;
}
