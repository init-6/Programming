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

int field[1001][1001];

int main()
{
	int T; cin >> T;
	REP(c, T)
	{
		CLEAR(field, 0);
		int A; cin >> A;
		int lim = (A == 20) ? 6 : 16;
		FOR(i, 1, lim) FOR(j, 1, lim)
		{
			while(field[i][j] == 0)
			{
				int send_x = (i == 1) ? 2 : ((i == lim-1) ? lim-2 : i);
				int send_y = (j == 1) ? 2 : ((j == lim-1) ? lim-2 : j);

				cout << send_x << " " << send_y << "\n";
				cout.flush();

				int receive_x, receive_y;
				cin >> receive_x >> receive_y;

				if(receive_x == 0 && receive_y == 0) break;
				if(receive_x == -1 && receive_y == -1) break;

				field[receive_x][receive_y] = 1;
			}
		}

	}
	
	return 0;
}
