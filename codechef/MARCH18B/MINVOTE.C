#include <bits/stdc++.h>
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
const int MOD = 1e9 + 7;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;
inline LL fpow(LL n, LL k, int p = MOD) {LL r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}


int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		VI x(N, 0); REP(i, N) cin >> x[i];

		LL prefix[N], suffix[N];
		prefix[0] = x[0]; suffix[N-1] = x[N-1];
		FOR(i, 1, N) prefix[i] = prefix[i-1] + x[i];
		for(int i = N-2; i >= 0; i--)
		suffix[i] = suffix[i+1] + x[i];

		// Get vote from previous minion
		VI ans(N, 0); FOR(i, 1, N) ans[i]++;
		// Get vote from next minion
		FOR(i, 0, N-1) ans[i]++;
		REP(i, N)
		{
			int l = i-2, r = i+2; // Start searching on either direction as long as this minion can vote;
			bool left = false, right = false;

			while(l >= 0 || r <= N-1)
			{
				if(left && right) break;

				if(l >= 0)
				{
					LL pre = suffix[l]; pre -= x[l]; pre -= suffix[i]; // Exclude ith and left pointer values to sum interval (left, i)
					if(pre <= x[i]) ans[l]++;
					else left = true;
					l--;
				}
				if(r <= N-1)
				{
					LL suf = prefix[r]; suf -= x[r]; suf -= prefix[i]; // Exclude ith and right pointer values to sum interval (i, right)
					if(suf <= x[i]) ans[r]++;
					else right = true;
					r++;
				}
			}
		}

		REP(i, N) cout << ans[i] << " ";
		cout << "\n";
		
	}
	
	return 0;
}
