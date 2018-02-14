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
typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N, K, S; cin >> N >> K >> S;
		int req = S*K;
		int poss = N*(S - S/7);

		if(req > poss) cout << "-1\n";
		else
		{
			int ans = req/N;
			if(ans > 0) ans += (req % N == 0) ? 0 : 1;
			if(req < N) ans++;

			cout << ans << "\n";
		}
	}
	
	return 0;
}
