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
	REP(c,T)
	{
		// Begin code
		int N; cin >> N;
		string a, b;
		cin >> a >> b;

		int A[26] = {0}, B[26] = {0};
		REP(i, a.sz) A[a[i] - 'a']++;
		REP(i, b.sz) B[b[i] - 'a']++;
		
		bool flag = false;
		REP(i, 26)
		{
			if((A[i] == 0 && B[i] != 0) || (A[i] != 0 && B[i] == 0))
			{
				cout << "Case #" << c+1 << ": " << "Fegla Won" << endl;
				flag = true;
				break;
			}
		}
		if(flag) continue;

		flag = false;
		int ans = 0, cnt = 0;
		string t = "";
		REP(i, a.sz)
		{
			if(A[a[i] - 'a'] == B[a[i] - 'a'] && t == b)
			{
				ans = cnt; flag = true;break;
			}
			else if(A[a[i] - 'a'] < B[a[i] - 'a'])
			{
				cnt ++;
				A[a[i] - 'a']++;
				t = a.substr(0,i) + a[i] + a.substr(i);
				a = t;
				cout << t << endl;
			}
		}
		cnt = 0;
		int ans1 = 0;
		bool flag2 = false;
		REP(i, b.sz)
		{
			if(A[b[i] - 'a'] == B[b[i] - 'a'] && t == a)
			{
				ans1 = cnt; flag2 = true;break;
			}
			else if(A[b[i] - 'a'] > B[b[i] - 'a'])
			{
				cnt ++;
				B[b[i] - 'a']++;
				t = b.substr(0,i) + b[i] + b.substr(i);
				b = t;
				cout << t << endl;
			}
		}
		ans = min(ans, ans1);
		if(flag || flag2)
		cout << "Case #" << c+1 << ": " << ans << endl;
		else
		cout << "Case #" << c+1 << ": " << "Fegla Won" << endl;
	}

	return 0;
}
