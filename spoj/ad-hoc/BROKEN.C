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
	int N;
	while(cin >> N && N)
	{
		string s;
		
		getline(cin,s);
		getline(cin,s);

		int count[256] = {0};

		int start = 0, end = 0;
		int ans = -1;
		int window = 0;
		while(end < s.sz)
		{
			if(window < N || count[s[end]] > 0)
			{
				// If i encounter any of the character i have seen so far and window <= N, keep extending the window until its exceeds N
				if(count[s[end]] == 0)
				window++; // Add this character from the window
				count[s[end]]++;
				end++;

				ans = max(ans, end - start);
			}
			else
			{
				// At this point, i have N+1 characters. TO add N+1 to the window, contract window from front till window <= N
				count[s[start]]--;
				if(count[s[start]] == 0)
				window--;	// Remove this character from window
				start++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
