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
		LL N, M; cin >> N >> M;
		LL N_odd = (N&1) ? N/2+1 : N/2;
		LL M_odd = (M&1) ? M/2+1 : M/2;
		LL N_even = N - N_odd;
		LL M_even = M - M_odd;

		LL num = (N_odd*M_even) + (N_even*M_odd);
		LL den = N*M;

		LL g = __gcd(num, den);
		num /= g;
		den /= g;

		cout << num << "/" << den << endl;
	}
	return 0;
}
