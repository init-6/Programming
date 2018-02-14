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

#define GI ({int t;scanf("%d",&t);t;})
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
		LL N, x; cin >> x >> N;

		LL all_sum = N*(N+1)/2 - x;
		if((all_sum&1) || (N < 4)) {cout << "impossible\n"; continue;}

		vector <LL> set1, set2;
		map<LL, int> M1, M2;
		
		LL expected_sum = (all_sum) >> 1;
		LL sum1 = 0LL, sum2 = 0LL;

		for(LL i = N; i > 0; --i)
		{
			if(i == x) continue;
			if(sum1 < expected_sum)
				sum1 += i, set1.pb(i), M1[i]=1;
			else sum2 += i, set2.pb(i), M2[i]=1;
		}

		reverse(all(set1)); reverse(all(set2));


		if(sum1 == sum2)
		{
			string ans = "";
			FOR(i, 1, N+1)
			{
				if(i == x) ans += "2";
				else if(M2[i] ==  1) ans += "0";
				else ans += "1";
			}
			cout << ans << "\n";
			continue;
		}

		LL diff = abs(sum1 - sum2) >> 1;
		int m = 0, n = 0;
		if(sum1 != sum2)
		{
			while(m < set2.sz && n < set1.sz)
			{
				LL d = set1[n] - set2[m];
				//cout << "d= " << d << " set1[n] == " << set1[n] << " set2[m] = " << set2[m] << "\n";
				if(d == diff)
				{
					sum1 -= diff; sum2 += diff;
					M2[set2[m]] = 0; M1[set2[m]] = 1;
					M1[set1[n]] = 0; M2[set1[n]] = 1;
					swap(set1[n], set2[m]);
					break;
				}
				else if(d > diff) m++;
				else n++;
			}
		}

		if(sum1 == sum2)
		{
			string ans = "";
			FOR(i, 1, N+1)
			{
				if(i == x) ans += "2";
				else if(M2[i] == 1) ans += "0";
				else ans += "1";
			}
			cout << ans << "\n";
			continue;
		}

		/*REP(i, set2.sz) cout << set2[i] << " ";
		cout << "\n";
		REP(i, set1.sz) cout << set1[i] << " ";
		cout << "\n";
		*/
		if(diff != 0)
		{
			LL l = set2.back(); set2.pop_back();	
			M2[l] = 0; M1[l] = 1;
			set1.insert(set1.begin(), l);
			sum2 -= l; sum1 += l;
			diff += l;
			m = n = 0;
			while(m < set2.sz && n < set1.sz)
			{
				LL d = set1[n] - set2[m];
				//cout << "d= " << d << " set1[n] == " << set1[n] << " set2[m] = " << set2[m] << "\n";
				if(d == diff)
				{
					sum1 -= diff; sum2 += diff;
					M2[set2[m]] = 0; M1[set2[m]] = 1;
					M1[set1[n]] = 0; M2[set1[n]] = 1;
					swap(set1[n], set2[m]);
					break;
				}
				else if(d > diff) m++;
				else n++;
			}
			if(sum1 == sum2)
			{
				string ans = "";
				FOR(i, 1, N+1)
				{
					if(i == x) ans += "2";
					else if(M2[i] == 1) ans += "0";
					else ans += "1";
				}
				cout << ans << "\n";
				continue;
			}
		}

		cout << "impossible\n";
	}
	return 0;
}
