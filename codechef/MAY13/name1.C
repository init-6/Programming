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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
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
	int T;cin >> T;
	while(T--)
	{
		string P1,P2;
		cin >> P1 >> P2;
		int n;cin >> n;
		int count[26];
		memset(count,0,sizeof(count));
		REP(i,P1.sz)
		{
			count[P1[i] - 'a']++;
		}
		REP(i,P2.sz)
		{
			count[P2[i] - 'a']++;
		}
		string c;
		bool ok=true;
		REP(i,n)
		{
			cin >> c;
			REP(j,c.sz)
			{
				count[c[j] - 'a']--;
				if(count[c[j] - 'a'] < 0)
				{
					ok = false;
					break;
				}
			}
		}
		ok ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
