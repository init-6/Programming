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

queue <long long> Q;
vector <ll> squares;
vector <ll> ans;
map <ll, bool> M;

void foo()
{
	
	int S = 100000;

	FOR(i,1,S+1)
	{
		squares.pb((ll)i*i);
		M[(ll)i*i] = true;
	}
	
	REP(i,squares.sz)
	{
		ll cur = squares[i];
		bool good=true;
		while(cur) 
		{
			if(cur%10 != 4 && cur%10 != 9 && cur%10 != 1 && cur%10 != 0)
			{
				good = false;
				break;
			}
			else cur/=10;
		}
		if(good) 
		ans.pb(squares[i]);
	}

}

int main()
{
	foo();	
	int T;cin >> T;
	while(T--)
	{
		ll a,b;
		cin >> a >> b;
		int cnt=0;
		REP(i,ans.sz)
		{
			if(ans[i] >= a && ans[i] <= b)
			cnt++;
		}

		cout << cnt << endl;

	}
	return 0;
}
