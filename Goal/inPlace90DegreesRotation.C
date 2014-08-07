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
	int N;cin >> N;
	int matrix[N][N];
	REP(i,N) REP(j,N) cin >> matrix[i][j];

	cout << endl;
	REP(i,N)
	{
		REP(j,N)
		cout << matrix[i][j] << " ";
		cout << endl;
	}

	int layers = N/2;
	int length = N-1;

	REP(i,layers) FOR(j,i, length-i)
	{
		int t = matrix[i][j];
		matrix[i][j] = matrix[length-j][i];
		matrix[length-j][i] = matrix[length-i][length-j];
		matrix[length-i][length-j] = matrix[j][length-i];
		matrix[j][length-i] = t;
	}

	cout << endl;
	cout << "After rotation by 90 degrees clockwise" << endl;
	REP(i,N)
	{
		REP(j,N)
		cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
