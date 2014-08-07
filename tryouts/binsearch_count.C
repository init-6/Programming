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

int rightmost_bs(VI v, int key)
{
	int low = 0, high = v.sz-1;

	int ret = -1;
	while(low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if(v[mid] == key)
		ret = mid, low = mid+1;
		else if(v[mid] > key)
		high = mid-1;
		else low = mid+1;
	}

	return ret;
}

int leftmost_bs(VI v, int key)
{
	int low = 0, high = v.sz-1;

	int ret = -1;
	while(low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if(v[mid] == key)
		ret = mid, high = mid-1;
		else if(v[mid] > key)
		high = mid-1;
		else low = mid+1;
	}

	return ret;
}

int count(VI v, int key)
{
	int lmost = leftmost_bs(v, key);
	int rmost = rightmost_bs(v, key);

	cout << "leftmost : " << lmost << "\nrightmost : " << rmost << endl;

	if(lmost == -1 && rmost == -1)
	return -1;

	return rmost - lmost + 1;
}

int main()
{
	int N; cin >> N;
	VI inp(N, 0);
	REP(i, N) cin >> inp[i];

	cout << "Enter the element to be searched and counted\n";
	int x; cin >> x;

	int ans = count(inp, x);
	ans == -1 ? cout << "Not found\n" : cout << ans << endl;

	return 0;
}
