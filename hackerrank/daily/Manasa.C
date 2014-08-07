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

set <int> ans;

void go(int A, int B, int last, int N)
{
	if(N == 1)
	ans.insert(last);
	else
	{
		go(A, B, last + A, N-1);
		go(A, B, last + B, N-1);
	}
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N, A, B;
		ans.clear();
		cin >> N >> A >> B;
		go(A, B, 0, N);
		set <int> :: iterator it = ans.begin();
		for(; it != ans.end(); ++it) cout << *it << " ";
		cout << endl;
		//cout << ans.sz << endl;
	}

	return 0;
}
