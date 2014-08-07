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

const int MAXN = 3e6 + 1;
const int MOD = 1e6;

int val[MAXN];

int main()
{
	int T; scanf("%d", &T);;
	while(T--)
	{
		int N; scanf("%d", &N);
		int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
		val[0] = d;

		LL term1=0, term2=0;
		FOR(i,1,N)
		{
			term1 = ((((val[i-1]%MOD)*(val[i-1]%MOD))%MOD)*(a%MOD))%MOD;
			term2 = ((val[i-1]%MOD)*(b%MOD))%MOD;

			LL v1 = ((term1 % MOD) + (term2 % MOD))%MOD;
			LL v2 = ((v1%MOD)+(c%MOD)) % MOD;
			val[i] = v2;
		}

		//sort(val, val+N);

		bool turn = true;

		LL cost1 = 0, cost2 = 0;

		REP(i,N)
		{
			if(turn)
			{
				cost1 += val[i];
				turn = false;
			}
			else
			{
				cost2 += val[i];
				turn = true;
			}
		}

		LL diff = abs(cost1 - cost2);

		printf("%lld\n", diff);

	}

	return 0;
}
