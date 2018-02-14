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
		int N, M, X, K; cin >> N >> M >> X >> K;
		string s; cin >> s;
		int ow = 0, ew = 0; REP(i, s.sz) if(s[i] == 'E') ew++; else ow++;

		FOR(i, 1, M+1)
		{
			if(i&1) {int wc = min(ow, X); N -= wc; ow -= wc;}
			else {int wc = min(ew, X); N -= wc; ew -= wc;}

		}

		N <= 0 ? cout << "yes\n" : cout << "no\n";
	}
	
	return 0;
}
