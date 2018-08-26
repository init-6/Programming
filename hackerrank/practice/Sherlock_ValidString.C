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
	string s; cin >> s;
	VI c(26, 0);
	REP(i, s.sz) c[s[i] - 'a']++;
	cout << "\n";

	set <int> S(all(c));S.insert(0);
	set <int > :: iterator it = S.end();
	--it;

	if(S.sz == 2) { cout << "YES\n"; return 0;}
	if(S.sz == 3) { int x = *it; cout << x << "\n"; --it;/*S.erase(S.end());*/ int y = *it; cout << y << "\n";if(x == y+1) cout << "YES\n"; else cout << "NO\n"; return 0; }

	cout << "NO\n";
	
	return 0;
}
