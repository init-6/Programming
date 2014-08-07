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
	int prev_min_area = INT_MAX, prev_max_area = INT_MIN;
	int minidx = 0;int maxidx = 0;
	REP(i,T)
	{
		int x1,y1,x2,y2,x3,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int cur_area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)); // Actual area is num/2; To avoid double, dont divide by 2;
		if(cur_area <= prev_min_area)
		minidx = i+1,prev_min_area = cur_area;
		if(cur_area >= prev_max_area)
		maxidx = i+1,prev_max_area = cur_area;
	}

	cout << minidx << " " << maxidx << endl;
	return 0;
}
