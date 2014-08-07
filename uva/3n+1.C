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
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

ULL go(ULL n)
{
	if(n == 1) return 1;
	if(n & 1) return 2 + go((3*n+1)>>1);
	else return 1 + go(n >> 1);
}

int main()
{
	ULL l,r;

	while(cin >> l >> r)
	{
		cout << l << " " << r << " ";
		ULL start = min(l,r);
		ULL end = max(l,r);
		ULL maxx = 0;

		for(ULL i = start; i <= end; ++i)
		maxx = max(maxx, go(i));

		cout << maxx << endl;
	}
	return 0;
}
