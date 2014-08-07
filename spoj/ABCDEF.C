#include <vector>
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
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
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

int main()
{
	int N;scanf("%d", &N);;
	int A[N];
	REP(i,N)
	{
		scanf("%d", &A[i]);
	}
	int def[1000005];
	int cnt = 0, rhs=0, lhs=0;
	REP(i,N)
	{
		if(A[i])
			REP(j,N)
			{
				REP(k,N)
				{
					rhs = A[i]*(A[j] + A[k]);
					def[cnt++] = rhs;
				}
			}
	}
	sort(def, def+cnt);
	int ans = 0;
	REP(i,N)
	{
		REP(j,N)
		{
			REP(k,N)
			{
				lhs = (A[i]*A[j] + A[k]);
				ans += upper_bound(def, def+cnt, lhs) - lower_bound(def, def+cnt, lhs);
			}
		}
	}

	cout << ans << endl;
	return 0;

}
