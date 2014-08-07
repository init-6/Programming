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

const int MOD = 1e9 + 7;

void matmul(LL A[][3], LL B[][3])
{
	LL ret[3][3] = {{0}};
	REP(i, 3)
	REP(j, 3)
	REP(k, 3)
	ret[i][j] = ( ( ret[i][j] % MOD) + ( ( (A[i][k] % MOD) * (B[k][j] % MOD ) ) % MOD ) ) % MOD;

	REP(i, 3) REP(j, 3) A[i][j] = ret[i][j];
}

LL matexp(LL A[][3], LL N)
{
	LL res[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }; // Identity matrix to begin with;
	while(N)
	{
		if(N & 1)
		matmul(res, A);
		matmul(A,A);
		N >>= 1;
	}

	return res[0][0];
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		LL N; cin >> N;
		LL res[3][3] = { {0, 0, 1}, {1, 0, 0}, {0, 1, 1} }; // A^N using fast matrix exponentiation yields the result.
		LL ans = matexp(res, N+5);

		cout << ans << endl;
	}
	return 0;
}
