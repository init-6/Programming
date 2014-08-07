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

const LL MOD=1000000007;
int main()
{
	int T;cin >> T;
	while(T--)
	{
		int Q,k;
		cin >> Q >> k;
		VI A,B,C;
		int x;
		REP(i,k)
		{
			cin >> x;B.pb(x);	
		}
		REP(i,k)
		{
			cin >> x;C.pb(x);	
		}

		int l,r;
		VI left,right;
		REP(i,Q)
		{
			cin >> l >> r;
			left.pb(l);right.pb(r);
		}
		VI mx = right;
		sort(all(mx));

		REP(i,k) A.pb(B[i]);
		
		FOR(i,k,mx[mx.sz-1])
		{
			LL sum = 0;
			REP(j,k)
			{
				LL n = ((C[j]%MOD)*(A[i-j-1]%MOD))%MOD;
				sum = (sum + n)%MOD;
			}
			A.pb(sum);
		}


		REP(i,left.sz)
		{
			VI ans(A.begin() + left[i]-1, A.begin() + right[i]);
			sort(all(ans));
			REP(j,ans.sz)
			{
				cout << ans[j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}
