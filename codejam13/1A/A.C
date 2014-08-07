#include <vector>
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

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define len length()
#define mkp make_pair
#define pi acos(-1)
typedef long long LL;
typedef vector <int> VI;
typedef pair<int, int> PI;

int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		long long int t,r,i=0,ans=0;
		cin >> r >> t;
		while(t > 0){
			t -= (2*r + (i*4)+1);i++;
			if(t>=0)ans++;
		}

		cout << "Case #" << c+1 << ": " << ans << endl;
	}

	return 0;
}
