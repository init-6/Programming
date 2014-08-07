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

map <LL, LL> M;

int main()
{
	FOR(a, 1, 3001)
	{
		FOR(b, a+1, 3001)
		{
			LL cc = a*a + b*b;
			int c = sqrt(cc);
			if(c*c == a*a + b*b && a < b && b < c)
			M[a+b+c] = max(M[a+b+c], (LL) a*b*c);
		}
	}

	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		LL ans = -1;
		bool good = false;

		if(M.find(N) != M.end())
		cout << M[N] << "\n";
		else cout << -1 <<"\n";

	}

	return 0;
}
