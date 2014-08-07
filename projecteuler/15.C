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

LL C[1002][1002];

void comb()
{
	REP(i, 1002)
	C[i][0] = 1, C[i][i] = 1;

	REP(i, 1002)
	REP(j, 1002)
	{
		if(j < i)
		C[i][j]	= ((C[i-1][j] % MOD) + (C[i-1][j-1] % MOD) ) % MOD;
	}
}

int main()
{
	int T; cin >> T;
	comb();
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		cout << C[N+M][M] << "\n";
	}

	return 0;
}
