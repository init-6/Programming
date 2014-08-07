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


const int MAX = 100000;
int main()
{

	int primes[MAX];
	memset(primes,0,sizeof(primes));

	bool isprime[100000];
	memset(isprime,1,sizeof(isprime));

	isprime[0] = isprime[1] = false;
	int n = sqrt(100000);

	//Sieve
	FOR(j,2,n+1)
	{
		if(isprime[j])
		{
			for(int k = j*j; k <= 100000; k += j)
			{
				isprime[k] = false;
			}
		}
	}

	int k = 0;
	int count[100000];
	memset(count, 0, sizeof(count));
	REP(i,100000)
	{
		if(isprime[i])
		{
			count[i+1] = 1;
			primes[k++] = i;
		}
	}
	cout << k << endl;
	REP(i, k)
	{
		for(int j = primes[k]; j <= 100000; j += primes[i])
		{
			count[j]++;
		}
	}

	int T;cin >> T;
	// Main loop
	while(T--)
	{
		int A,B,K;
		int ans = 0;
		cin >> A >> B >> K;
		FOR(i,A,B+1)
		{
		}
		cout << ans << endl;
	}

	return 0;
}
