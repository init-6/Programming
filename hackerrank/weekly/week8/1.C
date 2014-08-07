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
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

string one = "Richard", two = "Louise";

int main()
{
	ULL N;
	int T; cin >> T;

	while(T--)
	{
		cin >> N;
		if(N == 1)
		{
			cout << one << "\n";
			continue;
		}

		int steps = 0;
		while(N > 1)
		{
			int val = log2(N);

			if((N & (N-1)) == 0)
			N >>=1;
			else
			N -= (ULL) (1ULL << val);

			steps++;
			if(N == 1)
			break;
		}

		steps & 1 ? cout << two << "\n" : cout << one << "\n";
	}
	return 0;
}
