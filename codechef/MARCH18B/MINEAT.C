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

int poss(VI v, int x)
{

	int val = 0;
	REP(i, v.sz)
	val += ((v[i]/x) + (v[i] % x == 0 ? 0 : 1));

	return val;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N, H; cin >> N >> H;
		VI bananas(N, 0); REP(i, N) cin >> bananas[i];

		int low = 1, high = bananas[N-1], mid = 0;

		int steps = 0;
		while(steps <= 64)
		{
			//cout << "Before low = " << low << " mid = " << mid << " high = " << high << "\n";
			steps++;

			mid = low + ((high - low) >> 1);

			if(poss(bananas, mid) > H)
			low = mid + 1;
			else high = mid;
			//cout << "After low = " << low << " mid = " << mid << " high = " << high << "\n";

		}

		cout << (low + ((high - low) >> 1)) << "\n";

	}
	return 0;
}
