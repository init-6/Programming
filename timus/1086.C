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
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

bool isprime[1<<18];
int primes[15001];

void sieve()
{
	isprime[0] = isprime[1] = false;
	int n = sqrt(1<<18);
	for(int i = 2;i <= n;i++)
	{
		if(isprime[i])
		{
			for(int j = i*i;j<= (1<<18);j+=i)
			isprime[j] = false;
		}
	}
}

int main()
{
	CLEAR(primes,0);
	CLEAR(isprime,true);
	sieve();
	int c = 0;
	REP(i,1<<18)
	{
		if(isprime[i] && c <= 15000)
		primes[c++] = i;
	}
	int k;cin >> k;
	while(k--)
	{
		int idx;cin >> idx;
		cout << primes[idx-1] << endl;
	}

	return 0;
}
