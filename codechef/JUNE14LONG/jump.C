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

const int MAX = 1e5 + 10;
int dp[MAX];
int jumps[10];

int main()
{
	string s; cin >> s;
	REP(i, s.sz) dp[i] = i; // Minimum distance to reach ith digit initially is i - Initialize!
	REP(i, 10) jumps[i] = 100001; // jumps[i] = minimum distance to reach the digit i from start

	// base cases
	jumps[s[0] - '0'] = 0;
	dp[s.sz] = 100010; // sentinel for j loop last element below
	REP(i, 10)
	{
		FOR(j, 1, s.sz)
		{
			// Minimum of reaching i from left and right
			int cur_min = min(dp[j-1]+1, dp[j+1]+1); // refer sentinel for index out of bounds "j+1"
			// Minimum distance to reach i from any other digit i
			cur_min = min(cur_min, jumps[s[j] - '0'] + 1);

			//Update the dp and jumps array
			dp[j] = min(dp[j], cur_min);
			jumps[s[j]-'0'] = min(jumps[s[j]-'0'], cur_min);
		}
	}

	cout << dp[s.sz-1] << endl; // Bottom-up dp. Answer is dp[input_length]

	return 0;
}
