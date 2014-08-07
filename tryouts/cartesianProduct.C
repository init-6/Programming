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


static int cnt = 0;
void go(VVI &sets, VI &cur, int k)
{
	if(k == sets.sz)
	{
		// Print the cur vector that has one combination
		#ifdef DEBUG
		cout << "Voila! Combination " << ++cnt << " found : \n";
		#endif
		REP(i, cur.sz)
		cout << cur[i] << " ";
		cout << "\n";
	}
	else
	{
		REP(i, sets[k].sz)
		{
			cur[k] = (sets[k][i]);
			go(sets, cur, k+1);
		}
	}
}

int main()
{
	#ifdef DEBUG
	cout << "Enter number of combinations: \n";
	#endif
	int N; cin >> N;
	VVI sets;
	REP(i, N)
	{
		#ifdef DEBUG
		cout << "Enter the number of values in combination " << i+1 << " : \n";
		#endif
		VI inp; int m, val; cin >> m;
		#ifdef DEBUG
		cout << "Enter " << m << " values for combination " << i+1 << " :\n";
		#endif
		REP(j, m) { cin >> val; inp.pb(val); }
		sets.pb(inp);
	}

	VI cur(sets.sz, 0);
	go(sets, cur, 0);
	#ifdef DEBUG
	cout << "Total " << cnt << " Combinations are found as a result of cartesian product over " << N << " sets. \n";
	#endif

	return 0;
}
