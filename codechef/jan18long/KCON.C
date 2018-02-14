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

#define GI ({int t;scanf("%d",&t);t;})
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

LL kadane(vector <LL> a)
{
	LL max_so_far = a[0];
	LL cur_max = a[0];

	FOR(i, 1, a.sz)
	{
		cur_max = max(a[i], cur_max + a[i]);
		max_so_far = max(max_so_far, cur_max);
	}

	return max_so_far;
}

pair < LL, PI > maxsubarraysum(vector<LL> a)
{
	LL max_so_far = INT_MIN, max_ending_here = 0,
	    start =0, end = 0, s=0;

	for (int i=0; i<a.sz; i++ )
	{
		max_ending_here += a[i];

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i+1;
		}
	}

	pair < LL, PI > ret = mkp(max_so_far, mkp(start, end));

	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		LL N, K; cin >> N >> K;
		vector <LL> a(N, 0LL);
		REP(i, N) cin >> a[i];

		LL mx1 = kadane(a);

		vector <LL> b(2*N, 0LL);
		REP(i, 2*N)
			b[i] = a[i%N]; 

		//cout << "b : \n";

		//REP(i, K*N) cout << a[i%N] << " ";
		//cout << "\n";

		pair < LL, PI > ret = maxsubarraysum(b);

		if(K==1)
			cout << mx1 << "\n";
		else
		{
			int start = ret.second.first;
			int end = ret.second.second;
			LL mx2 = ret.first;

			//cout << "start = " << start << " end = " << end << "\n";
			//cout << "mx2 = " << mx2 << "\n";

			LL suma = accumulate(all(a), 0LL);

			LL sum_boundary = 0;
			bool seen[N+1]; REP(i, N+1) seen[i] = false;
			FOR(i, start, end+1)
			{
				seen[i%N] = true;
			}

			REP(i, N) sum_boundary += (seen[i] ? a[i] : 0);
			//cout << "sum_boundary = " << sum_boundary << "\n";

			LL max_ = suma - sum_boundary;
			//cout << "max_ = " << max_ << "\n";

			if(max_ == 0)
			{
				cout << mx2 + (K-2)*(mx2 - mx1) << "\n";
			}
			else if(mx2 + max_ < 0)
			{
				cout << mx2 << "\n";
			}
			else
			{
				cout << mx2 + (K-2)*(mx2 + max_) << "\n";
			}

		}
	}
	return 0;
}
