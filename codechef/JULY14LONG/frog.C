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

map <int, int> color;

int main()
{
	int N, K, P;
	cin >> N >> K >> P;
	VPI nodes(N);
	REP(i, N)
	{
		cin >> nodes[i].first;
		nodes[i].second = i+1;
	}

	sort(all(nodes));
	int col = 1;

	bool good = true;
	color[nodes[0].second] = col;
	REP(i, N-1)
	{
		good &= (nodes[i+1].first - nodes[i].first <= K);
		if(!good)
		good=true, col++;
		color[nodes[i+1].second] = col;
	}

	int A, B;
	REP(i, P)
	{
		cin >> A >> B;
		color[A] != color[B] ? cout << "No" << endl : cout << "Yes" << endl;
	}

	return 0;
}
