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
typedef vector<string> VS;


int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		// Begin code
		int N; cin >> N;
		int L; cin >> L;
		string t;
		vector <string> s,d;
		REP(i, N)
		{
				cin >> t;
				s.pb(t);
		}
		REP(i, N)
		{
				cin >> t;
				d.pb(t);
		}

		sort(all(d));

		queue <pair < vector <string>, int > > Q;
		Q.push(mkp(s, 0));

		map < VS, bool > M;

		int dist = 0;
		bool flag = false;
		while(!Q.empty())
		{
			VS x = Q.front().first;
			int dd = Q.front().second;
			Q.pop();
			//cout << " Popping " << endl;
			//REP(i, x.sz)
			//cout << x[i] << endl;
			if(M[x]) continue;
			M[x] = true;
			VS tmp = x;
			sort(all(x));
			if(x == d)
			{
				dist = dd;
				flag = true;
				break;
			}
			else
			{
				VS next(tmp);
				dd++;
				REP(i, L)
				{
					REP(j, N)
					next[j][i] = ((tmp[j][i] - '0') ^ 1) + 48;
					//cout << "Generating states " << endl;
					//REP(l, next.sz)
					//cout << next[l] << endl;
					if(!M[next])
					{
						//cout << "Pushing " << endl;
						//REP(k, next.sz)
						//cout << next[k] << endl;
						Q.push(mkp(next, dd));
					}
				}
			}

		}
	
		if(flag)
		cout << "Case #" << c+1 << ": " << dist << endl;
		else
		cout << "Case #" << c+1 << ": " << "NOT POSSIBLE" << endl;
	}

	return 0;
}
