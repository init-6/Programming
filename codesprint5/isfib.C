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
	int T;cin >> T;
	map <int, bool > M;
	vector <LL> fib;
	fib.pb(0);fib.pb(1);
	M[0] = true;M[1] = true;
	int i = 1;
	while(fib[i] <= (LL) 10000000000)
	{
		i++;
		LL x = fib[i-1] + fib[i-2];
		fib.pb(x);
		M[fib[i]] = true;
	}
	
	while(T--)
	{
		LL N; cin >> N;
		string yes = "IsFibo", no = "IsNotFibo";
		if(M[N]) cout << yes << endl;
		else cout << no << endl;
	}

	return 0;
}
