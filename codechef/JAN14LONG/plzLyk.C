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
	string win = "ALIVE AND KICKING";
	string lose = "DEAD AND ROTTING";
	while(T--)
	{
		int L,D,S,C; cin >> L >> D >> S >> C;
		LL m = (1+C);
		LL cur = S;
		if(D == 1)
		{
			cur >= L ? cout << win << endl : cout << lose << endl;
			continue;
		}

		bool yes = false;
		for(int d = 1; d<= D-1;d++)
		{
			cur *= m;
			if(cur >= L)
			{	
				yes = true;
				cout << win << endl;
				break;
			}
		}
	
		if(!yes)
		cout << lose << endl;

	}

	return 0;
}
