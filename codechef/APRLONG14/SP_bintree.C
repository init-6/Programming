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
	REP(t,N)
	{
		int i,j; scanf("%d%d", &i, &j);
		string path1, path2;		

		while(i)
		path1 += (char) (i%2 + '0'),i >>= 1;
		
		while(j)
		path2 += (char) (j%2 + '0'),j >>= 1;

		reverse(all(path1));
		reverse(all(path2));

		int n1 = path1.sz, n2 = path2.sz;
		int i1 = 0, i2 = 0;

		while(i1 < n1 && i2 < n2 && path1[i1] == path2[i2])
		i1++,i2++;

		int add1 = path1.substr(i1).sz;
		int add2 = path2.substr(i2).sz;

		printf("%d\n", add1+add2);

	}

	return 0;
}
