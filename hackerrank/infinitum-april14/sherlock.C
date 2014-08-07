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
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);
		int K; scanf("%d", &K);
		LL mx = (LL)N*(LL)K;
		int start = 1, end = N/2+1;
		int ans = 0;
		FOR(i, start, end)
		{
			if((LL)i * (LL) (N-i) <= mx)
			{
				ans+=2;
				//cout << i << " " << N-i << endl;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
