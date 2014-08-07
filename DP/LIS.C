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
	VI x(N,0);
	REP(i,N)
	cin >> x[i];


	REP(i,N) cout << x[i] << " ";
	cout << endl;

	int LIS[N];memset(LIS, 0, sizeof(LIS));
	REP(i,N) LIS[i] = 1;

	FOR(i,1,N)
	{
		FOR(j,0,i)
		{
			if(x[i] > x[j] && LIS[i] < LIS[j]+1)
			LIS[i] = LIS[j]+1;
		}
	}

	int l = 1;

	REP(i,N)
	l = max(l,LIS[i]);

	REP(i,N)
	cout << LIS[i] << " ";
	cout << endl;

	cout << l << endl;

	return 0;
}
