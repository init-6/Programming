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
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		int arr[2*N];
		map <int, bool> event_entry, event_exit;
		REP(i, 2*N)
		{
			cin >> arr[i];
			if(i%2)
			event_exit[arr[i]] = true;
			else
			event_entry[arr[i]] = true;
		}

		sort(arr, arr + (2*N));

		int ans = 0, cnt = 0;
		REP(i, 2*N)
		{
			if(event_entry[arr[i]])
			cnt ++;
			else if (event_exit[arr[i]])
			cnt --;

			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}

	return 0;
}
