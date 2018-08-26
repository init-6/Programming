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

#define MAX_BIT_LEN 31

int main()
{
	int N, Q; cin >> N >> Q;
	string bits[N];

	REP(i, N)
	{
		LL x; cin >> x;
		bits[i] = bitset<MAX_BIT_LEN>(x).to_string();
	}

	int cnt[N][31];
	REP(i, 31) cnt[0][i] = bits[0][i] - '0';
	FOR(i, 1, N) REP(j, 31)
	cnt[i][j] = cnt[i-1][j] + (bits[i][j] - '0');

	REP(i, Q)
	{
		int L, R; cin >> L >> R;
		L--, R--;
		LL ans[31] = {0};

		REP(k, 31)
			if(!L) ans[k] = cnt[R][k]; else ans[k] = cnt[R][k] - cnt[L-1][k];
		int interval = R-L+1;
		REP(k, 31)
			if((interval >> 1) < ans[k]) ans[k] = 0;
			else if(!(interval & 1) && (interval >> 1) == ans[k])
				ans[k] = 0;
			else ans[k] = 1;

		LL m = 1, sum = 0;
		RREP(i, 31) sum += (ans[i]*m), m <<= 1;
		cout << sum << "\n";
	}

	
	return 0;
}
