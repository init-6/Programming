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

// Fibonacci

int main()
{
	unsigned long long fibo[94] = {0};
	fibo[0] = 0, fibo[1] = 1, fibo[2] = 1;
	FOR(i, 3, 94)
	fibo[i] = fibo[i-1] + fibo[i-2];

	int T; cin >> T;
	while(T--)
	{
		LL N; cin >> N;
		unsigned long long ans = 0;
		for(int i = 0; i < 94; i++)
		{
			if(fibo[i] > N) break;
			if(fibo[i] % 2 == 0)
			ans += fibo[i];
		}
		cout << ans << endl;
	}


	return 0;
}
