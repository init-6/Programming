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

const int MAX=1000000;
const int MIN=1000;

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

// Returns a%b. Remember, to find the next number from L that p divides, can be computed in constant time.
LL mod(LL a, LL b) 
{
	if(b < 0)
	     return mod(-a, -b); 
	LL ret = a % b;
	if(ret < 0)
	ret += b;

	return ret;
}

LL getStart(LL left, LL p)
{
	if(left != p)
	return (left + mod(-left,p));
	else return (left + p);
}

int main()
{
	CLEAR(isprime,true);
	sieve();
	// Store all primes till 10^6
	REP(i,1000001)
	{
		if(isprime[i])
		{
			primes.pb(i);
		}
	}

//	cout << primes.sz << endl;


	int T;cin >> T;
	while(T--)
	{
		long long int L,R;cin >> L >> R;
		LL cnt = 0;
		//map <long long, bool> good;

		//good[1] = false;
		REP(i,primes.sz)
		{
			LL cur = primes[i];
			//good[cur] = true;
			int exp = 1;
			while(cur <= 1000000000000LL)
			{
				cur*=primes[i];
				exp++;
				if(isprime[exp+1] && cur >= L && cur <= R)
				//good[cur] = true;
				cnt++;
			}
		}


		long long int store[R-L+1];
		memset(store,0,sizeof(store));
		if(L==1) store[0] = 1;
		

		// Interval sieving begins.
		
		REP(i,primes.sz)
		{
			LL start = getStart(L,primes[i]);
			if(start >= 1 && start <= 1000000) if(isprime[start]) start += primes[i];
			//cout << start << endl;
			for(LL j=start; j <= R;j+=primes[i])
			{
				store[j-L] = 1;
			}
		}


		//LL cnt=0;
		for(LL i = L;i <= R; i++)
		{
		//	if(good[i]) 
		//	{
		//		cnt++;
		//		continue;
		//	}
			if(store[i-L] == 0)
			{
				cnt++;
				//cout << i << endl;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}
