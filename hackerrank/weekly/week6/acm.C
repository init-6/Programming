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
	int M, N; cin >> M >> N;
	int maxx = 0, ans = 0;
	vector <string> v(M, "");
	REP(i, M) cin >> v[i];

	REP(i, M)
	{
		FOR(j, i+1, M)
		{
			int cnt = 0;
			REP(k, N)
			cnt += ((v[i][k] - '0') || (v[j][k] - '0'));
			maxx = max(cnt, maxx);
		}
	}

	REP(i, M)
	{
		FOR(j, i+1, M)
		{
			int cur = 0;
			REP(k, N)
			cur += ((v[i][k] - '0') || (v[j][k] - '0'));
			if(cur == maxx)
			ans++;
		}
	}
	cout << maxx << endl; cout << ans << endl;
	return 0;
}
