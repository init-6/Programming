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
	
	set <LL> store;
	queue <LL> Q;
	Q.push(9);
	store.insert(9);
	LL n = Q.front();
	while(n <= (LL)1e18)
	{
		Q.pop();
		Q.push((LL) n*10);Q.push((LL) n*10+9);
		n = Q.front();
		store.insert(n);
	}

	vector <LL> V(all(store));
	LL val[500] = {0};
	FOR(j,1,501)
	{
		REP(i,V.sz)
		{
			if(V[i]%j == 0)
			{
				val[j] = V[i];
				break;
			}
		}
	}

	int T; cin >> T;
	while(T--)
	{
		int N;cin >> N;
		cout << val[N] << endl;
	}

	return 0;
}
