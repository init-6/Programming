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

int main()
{
	int T;cin >> T;
	int N[10];
	int maxnum = -1;
	REP(i,T)
	{
		cin >> N[i];
		maxnum = maxnum > N[i] ? maxnum : N[i];
	}

	int lim = ceil(sqrt(maxnum));
	
	REP(i,T)
	{
		int ans = 0;
		REP(d,lim)
		{
			if(N[i]%(d+1) == 0)
			{
				int haha = d+1;
				while(haha != 0)
				{
					if((haha % 10 == 4) || (haha % 10 == 7))
					{
						ans++;
						break;
					}
					haha/=10;
				}
				int pair = N[i]/(d+1);
				if(pair > lim)
				{
					int hehe = pair;
					while(hehe != 0)
					{
						if((hehe % 10 == 4) || (hehe % 10 == 7))
						{
							ans++;
							break;
						}
						hehe/=10;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;

}
