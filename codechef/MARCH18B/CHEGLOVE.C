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

bool poss(VI x, VI y)
{
	bool ret = true;
	REP(i, x.sz) ret = ret && (x[i] <= y[i]);
	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		VI fingers(N, 0), gloves(N, 0);
		REP(i, N) cin >> fingers[i];
		REP(i, N) cin >> gloves[i];

		bool front = poss(fingers, gloves);
		reverse(all(gloves));
		bool back = poss(fingers, gloves);

		if(front && back) cout << "both\n";
		else if(front) cout << "front\n";
		else if(back) cout << "back\n";
		else cout << "none\n";
	}
	
	return 0;
}
