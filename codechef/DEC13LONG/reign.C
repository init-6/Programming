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
		int N,K; scanf("%d%d", &N, &K);
		LL prefix[100001] = {0};LL suffix[100001] = {0};
		LL inp[N];

		REP(i,N)
		scanf("%lld", &inp[i]);
		
		LL cur_mx = inp[0];
		LL max_sum = inp[0];
		prefix[0] = cur_mx;
		FOR(i,1,N)
		{
			cur_mx = max(inp[i], cur_mx+inp[i]);
			max_sum = max(max_sum, cur_mx);
			prefix[i] = max_sum;
		}
		cur_mx = inp[N-1];
		max_sum = inp[N-1];
		suffix[N-1] = cur_mx;
		RREP(i,N-1)
		{
			cur_mx = max(inp[i], cur_mx+inp[i]);
			max_sum = max(max_sum, cur_mx);
			suffix[i] = max_sum;
		}

		//REP(i,N) cout << prefix[i]<< " ";cout<<endl;REP(i,N) cout << suffix[i] << " ";cout << endl;
		
		LL ans = prefix[0]+suffix[K+1];
		FOR(i,1,N-K-1)
		{
			ans = max(ans, prefix[i]+suffix[K+i+1]);
		}
		
		printf("%lld\n", ans);
	}

	return 0;
}
