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

char maze[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int i, int j, int row, int col)
{
	visited[i][j] = true;
	int d = 1;
	REP(x,4)
	if(!visited[i+dx[x]][j+dy[x]] && i+dx[x] >= 0 && i+dx[x] < row && j+dy[x] >= 0 && j+dy[x] < col && maze[i+dx[x]][j+dy[x]] == '.')
	d+=dfs(i+dx[x], j+dy[x], row, col);

	return d;
}

int main()
{
	int n, m;
	cin >> n >> m;
	REP(i,n) REP(j,m)
	cin >> maze[i][j];

	int ans = -1;

	REP(i,n) REP(j,m)
	if(maze[i][j] == '.' && !visited[i][j])
	ans = max(ans, dfs(i,j,n,m));


	cout << ans << endl;
	return 0;

}
