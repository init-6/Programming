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

LL calc(int base, int exp)
{
	LL prod = 1;
	while(exp)
	{
		if(exp & 1)
		prod = ( (prod % MOD) * (base % MOD) ) % MOD;
		exp >>= 1;
		base = ( ( base % MOD) * (base % MOD) ) % MOD;
	}

	return (prod % MOD);
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		int arr[N];
		REP(i,N) cin >> arr[i];

		unsigned long long int orsum = 0;
		REP(i,N) orsum = ((orsum % MOD) | (arr[i] % MOD) ) % MOD;
		
		LL fact = calc(2, N-1);

		LL ans = ( (orsum % MOD) * (fact % MOD) ) % MOD;
		
		cout << ans << endl;

	}
	return 0;
}
