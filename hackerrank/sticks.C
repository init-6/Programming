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
	VI h(N,0);

	REP(i,h.sz) cin >> h[i];
	if(N == 1) 
	{
		cout << 1 << endl;
		return 0;
	}

	sort(all(h));
	
	int cnt[1001] = {0};

	REP(i,h.sz) 
	{
		cnt[h[i]]++;
	}

	set <int> S(all(h));
	VI uniq(all(S));

	int sum = 0;
	REP(i,uniq.sz) sum += cnt[uniq[i]];
	REP(i,uniq.sz)
	{
		cout << sum << endl;
		sum -= cnt[uniq[i]];
	}

	
	return 0;
}
