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

LL foo(string s)
{
	LL score = 1, ret = 0;
	REP(i, s.sz)
		if(s[i] == 'S') ret += score;
		else score <<= 1;
	
	return ret;
}


int main()
{
	int T; cin >> T;
	REP(c, T)
	{
		LL D; cin >> D;
		string s; cin >> s;
		
		int ans = 0;
		while(foo(s) > D)
		{
			bool found = false;
			ans++;
			for(int i = s.sz-1; i > 0; i--)
			{
				if(s[i] == 'S' && s[i-1] == 'C')
				{
					swap(s[i], s[i-1]);
					found = true;
					break;
				}
			}
			if(!found) break;
		}

		if(foo(s) > D) cout << "Case #" << c+1 << ": IMPOSSIBLE\n";
		else cout << "Case #" << c+1 << ": " << ans << "\n";
	}
	return 0;
}
