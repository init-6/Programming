#include <vector>
#include <queue>
#include <climits>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std;

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
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

const int MOD = (1e9 + 7);


//Computes (a power x) mod MOD
LL modexp(LL a, LL x)
{
	LL ret = 1;
	while(x)
	{
		if(x&1)
		{
			ret = (ret * a) % MOD;
		}
		a = (a*a) % MOD;
		x >>= 1;
	}

	return ret;
}

// Use Fermat's little theorem to find pow(d,p)%p; where p = MOD;
LL multModInverse(LL d)
{
	return modexp(d, MOD-2);
}
// C(M,N)
// numerator = (M*(M-1)*(M-2)*....(M-N+1))
// denominator = (N*(N-1)*(N-2)*....*1)
// Compute modular inverse of denominator and multiply with numerator
LL comb(LL m, LL n)
{
	LL num = 1;
	REP(i,n)
	num = (num * (m-i)) % MOD;

	LL den = 1;
	FOR(i,1,n+1)
	den = (den * i) % MOD;

	return (num * multModInverse(den)) % MOD;

}

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int M,N;cin >> M >> N;
		cout << comb(M+N-2,N-1) << endl;
	}

	return 0;
}
