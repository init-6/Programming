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
	vector <int> V;
	int N,a,X;
	cin >> N;
	
	int minm = 0;
	bool good=false;
	REP(i,N)
	{
		cin >> a;
		V.pb(a);	
		if(a < 0)
		{
			good = true;
			// find the smallest
			minm = min(minm,a);
		}
	}
	cin >> X;
	ll cost = 0;

	//&& (-1)*minm > X
	if(minm < 0 && X > 1)
	{
		minm = (-1)*minm;
		int dif = 0;
		if(minm >= X)
		dif = minm - X + 1,cost += (ll) (minm - X + 1)*X;
		REP(i,V.sz)
		V[i] = V[i] < 0 ? V[i]+dif : V[i];
		int maxm = 0;
		ll sum = 0;
		REP(i,V.sz)
		{
			if(V[i] < 0)
			{
				maxm = max((-1)*V[i],maxm);
				sum += (-1)*V[i];
			}
		}
		if(sum > (ll) maxm*X)
		{
			cost += (maxm*X);
			REP(i,V.sz)
			V[i] = V[i] < 0 ? V[i]+maxm : V[i];
		}
	}

	//REP(i,V.sz)
	//{
		// Now all (-1)*V[i] < X
	//	cout << V[i] << " ";
	//}
	//cout << endl;

	REP(i,V.sz)
	{
		if(V[i] < 0)
		{
			int tmp = (-1)*V[i];
			if(tmp <= X || X < 2)
			cost += tmp;
		}
	}

	if(good)
	cout << cost << endl;
	else cout << "0" << endl;

	return 0;
}
