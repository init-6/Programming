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
		int R, C, M; cin >> R >> C >> M;

		if(R == 1 && C == 1)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M == 0)
			cout << "c" << endl;
			else cout << "Impossible" << endl;
			continue;
		}

		if(R == 1 && C == 2)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M == 0)
			cout << "c." << endl;
			else cout << "Impossible" << endl;
			continue;
		}


		if(R == 2 && C == 1)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M == 0)
			cout << "c\n.\n";
			else cout << "Impossible" << endl;
			continue;
		}

		if(R == 1 && C > 2)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M <= R*C-2)
			{
				cout << "c";
				REP(i,R*C-M-1) cout << ".";
				REP(i,M) cout << "*";
				cout << endl;
			}
			else cout << "Impossible" << endl;
			continue;
		}

		if(C == 1 && R > 2)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M <= R*C-2)
			{
				cout << "c" << endl;
				REP(i,R*C-M-1) cout << "." << endl;
				REP(i,M) cout << "*" << endl;
			}
			else cout << "Impossible" << endl;
			continue;
		}

		if(R == 2 && C == 2)
		{
			cout << "Case #" << c+1 << ": " << endl;
			if(M == 0)
			{
				cout << "c." << endl;
				cout << ".." << endl;
			}
			else cout << "Impossible" << endl;
			continue;
		}

		cout << "Case #" << c+1 << ": " << endl;
		if(M <= R*C-4)
		{
			int dots = R*C-4 - M;
			REP(i,R)
			{
				REP(j,C)
				{
					if(i == 0 && j == 0) cout << "c";
					else if(i <= 1 && j <= 1) cout << ".";
					else
					{
						if(dots > 0) 
						{
							cout << ".";
							dots--;
						}
						else cout << "*";
					}
				}
				cout << endl;
			}
		}
		else cout << "Impossible" << endl;

	}

	return 0;
}
