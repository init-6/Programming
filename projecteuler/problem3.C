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

const LL MAX=1e6 + 1;
const int MIN=1001;

bool isprime[1000001];
vector <int> primes;

void sieve()
{
	isprime[0] = isprime[1] = false;
	int n = MIN;
	for(int i = 2;i <= n;i++)
	{
		if(isprime[i])
		{
			for(int j = i*i;j<= MAX;j+=i)
				isprime[j] = false;
		}
	}
}

int main()
{
	int T; cin >> T;
	CLEAR(isprime, true);
	sieve();
	// Store all primes till 10^6
	REP(i,1000001)
	{
		if(isprime[i])
		{
			primes.pb(i);
		}
	}

	while(T--)
	{
		LL inp; cin >> inp;
		int idx = -1;
		bool first = false;
		RREP(i, primes.sz)
		if(inp % primes[i] == 0)
		{
			if(!first)
			idx = i, first = true;

			while(inp% primes[i] == 0)
			inp/=primes[i];
		}
		if(inp > primes[primes.sz-1])
		cout << inp << endl;
		else if(idx == -1)
		cout << inp << endl;
		else cout << primes[idx] << endl;
	}
	return 0;
}
