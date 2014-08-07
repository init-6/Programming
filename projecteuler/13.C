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
	int N; cin >> N;
	string s[N];
	REP(i, N)
	cin >> s[i];
	
	REP(i, N)
	{
		string t = s[i];
		reverse(all(t));
		s[i] = t;
	}

	string ans = "";
	LL carry = 0;
	REP(j, 50)
	{
		LL sum = 0;
		REP(i, N)
		{
			sum += (s[i][j] - '0');
		}
		sum += carry;
		carry = sum/10;
		ans += ((sum%10) + '0');
	}

	reverse(all(ans));
	int num = 0;
	LL tmp = carry;
	while(tmp)
	tmp/=10, num++;

	if(carry > 0)
	cout << carry << ans.substr(0,10-num) << endl;
	else
	cout << ans.substr(0,10) << endl;
	return 0;
}
