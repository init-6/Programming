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
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		VI boxes(N,0);
		int cnt[101];
		memset(cnt,0,sizeof(cnt));
		REP(i,N)
		{
			cin >> boxes[i];
			cnt[boxes[i]]++;
		}

		int K;cin >> K;
		bool seen[100001];
		REP(i,100001) seen[i] = false;

		int lim = K%2 ? K/2 : K/2+1;

		int ans = 0;
		FOR(i,0,lim+1)
		{
			cout << "Partitions : " <<  i << " " << K-i << endl;
			if(i == K-i) 
			{
				ans += (cnt[i]*(cnt[i]-1))/2;
				continue;
			}
			if(cnt[i] && cnt[K-i])
			{
				if(!seen[i] && !seen[K-i])
				{
					ans+= (cnt[i]*cnt[K-i]);
					seen[i] = seen[K-i] = true;
				}
			}
		}

		cout << ans << endl;

	}
}
