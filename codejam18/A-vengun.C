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

	REP(c, T)
	{
		LL D; cin >> D;
		string s; cin >> s;

		LL count_C = 0;
		REP(i, s.sz) if(s[i] == 'C') count_C++;

		LL maxPower = 1LL << count_C;
		LL cnt = 0;

		REP(i, s.sz-1)
			if(s[i] == 'C' && s[i+1] == 'S')
				cnt++;

		bool found = false;
		REP(i, cnt)
		{
			maxPower /= 2;
			if(maxPower <= D)
			{
				ans = i+1;
				found = true;
				break;
			}
		}

		if(found)
		cout << "Case #" << c << ": " << ans << "\n";
		else
		cout << "Case #" << c << ": IMPOSSIBLE" << "\n";
	}

	return 0;
}
