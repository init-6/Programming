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

const int MAX = 1e6 + 10;
VI primes;
bool isprime[MAX];

void sieve()
{
	int lim = sqrt(MAX);
	isprime[1] = isprime[0] = false;
	FOR(i, 2, lim)
	{
		if(isprime[i])
		{
			for(int j = i*i; j < MAX; j+=i)
			isprime[j] = false;
		}
	}
}

int main()
{
	int T; cin >> T;
	memset(isprime, true, sizeof(isprime));
	sieve();
	REP(i, 1000001)
	if(isprime[i]) primes.pb(i);
	while(T--)
	{
		int N;	cin >> N;
		cout << primes[N-1] << "\n";
	}

	return 0;
}
