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
		int x, y, z;
		VVI points;
		REP(i, 4)
		{
			cin >> x >> y >> z;
			VI p;
			p.pb(x); p.pb(y); p.pb(z);
			points.pb(p);
		}

		VVI vectors;

		FOR(i, 1, 4)
		{
			VI v; 
			REP(j, 3)
			v.pb(points[i][j] - points[0][j]);
			vectors.pb(v);
		}

		// Box product = v1.(v2xv3)
		VI cross;			// cross product components 
		cross.pb(vectors[0][1]*vectors[1][2] - vectors[0][2]*vectors[1][1]);
		cross.pb(vectors[0][0]*vectors[1][2] - vectors[1][0]*vectors[0][2]);
		cross.pb(vectors[0][0]*vectors[1][1] - vectors[1][0]*vectors[0][1]);

		string yes = "YES", no = "NO";

		(vectors[2][0]*cross[0] + vectors[2][1]*cross[1] + vectors[2][2]*cross[2]) == 0 ? cout << yes << endl : cout << no << endl;


	}
	return 0;
}
