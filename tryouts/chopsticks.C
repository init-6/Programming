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
	int N, D, x;
	cin >> N >> D;
	VI C;
	REP(i,N) {
	cin >> x;C.pb(x);}

	sort(all(C));

	if(N == 1) {
		cout << "0" << endl;
		return 0;
	}
	if( N == 2) {
		(abs(C[0] - C[1]) <= D) ? cout << "1" << endl : cout << "0" << endl;
		return 0;
	}

	int ans = 0;
	int i = 0;
	while(i < N-1)
	{
		if(C[i+1] - C[i] <= D)
		ans++, i+=2;
		else i++;
	}

	cout << ans << endl;
	return 0;
}
