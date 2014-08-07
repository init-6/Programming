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

bool isprime[2000001];

//void sieve()
//{
//	REP(i,2000001) isprime[i] = true;
//	isprime[0] = isprime[1] = false;
//
//	int n = sqrt(2000001);
//	FOR(i,2,n+1)
//	{
//		if(isprime[i])
//		{
//			for(int k = i*i; k <= 2000001;k+=i)
//			isprime[k] = false;
//		}
//	}
//}

int main()
{
//	sieve();
		int N;cin >> N;
		LL ans = ((4*(N-2))+1)%1000000007;
		if(N == 1) cout << "0" << endl;
		else
		cout << ans << endl;

	return 0;
}
