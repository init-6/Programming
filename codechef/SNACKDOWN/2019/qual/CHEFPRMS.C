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
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	set <int> semiprimes;
	REP(i, 25)
		FOR(j, i+1, 25)
		semiprimes.insert(primes[i]*primes[j]);

	//EACH(it, semiprimes) cout << *it << "\n";

	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
//		FOR(N, 1, 201) {
		bool found = false;

		FOR(num1, 1, N)
		{
			int num2 = N - num1;
			if(semiprimes.find(num1) != semiprimes.end() && semiprimes.find(num2) != semiprimes.end())
			{
				found = true;
				cout << "YES\n";
				//cout << "YES " << num1 << " " << num2 << "\n";
				break;
			}
		}

		if(!found) cout << "NO\n";
	}
//	}
	
	return 0;
}
