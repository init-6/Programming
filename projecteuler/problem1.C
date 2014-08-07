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

// Multiples of 3 or 5

LL getSum(int lim)
{
	return (LL) (lim)*(lim+1)/2;
}

LL go(int N, int m)
{
	return (LL) m*getSum(N);
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		
		int N3 = N/3, N5 = N/5, N15 = N/15;
		
		if(N%3 == 0 && N%5 == 0) N15--, N3--, N5--;
		else if(N%3 == 0) N3--;
		else if(N%5 == 0) N5--;

		LL ans = go(N3, 3) + go(N5, 5) - go(N15, 15);

		cout << ans << endl;
	}

	return 0;
}
