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

int main()
{
	int n;
	while(cin >> n && n)
	{
		int L[n];
		stack <int> S;
		int curmin = 1;
		REP(i,n)
		cin >> L[i];

		REP(i,n)
		{
			bool flag =true;
			if(L[i] > curmin)
			{
				if(S.empty())
				{
					S.push(L[i]);
					continue;
				}
				else
				{
					int t = S.top();
					while( t < L[i] && !S.empty())
					{
						if( t != curmin)
						{
							flag = false;
							break;
						}
						else
						{
							cout << t << endl;
							curmin++;
							S.pop();
							t = S.top();
						}
					}
					S.push(L[i]);
				}
			}
			else if(L[i] == curmin) curmin++;	// 3 1 2 5 4 
			else 
			{
				
			}

		}
	}

	return 0;
}
