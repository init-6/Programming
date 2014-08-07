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

unsigned long long int MOD[20];

int dp[1000001][20];

int main()
{
	int T; cin >> T;
	MOD[0] = 1;
	FOR(i,1,20)
	{
		MOD[i] = MOD[i-1]*10;
		//cout << MOD[i] << endl;
	}
	
	dp[0][0] = 0;
	FOR(i,1,19)
	dp[0][i] = 1;
	unsigned long long int fact = 1;
	FOR(i,1,1000001)
	{
		FOR(j,1,20)
		{
			fact = ((fact % MOD[j]) * (i % MOD[j])) % MOD[j];
			dp[i][j] = fact;
		}
	}

	REP(i,1000001) {
	REP(j,20)
	cout << dp[i][j] << " ";
	cout << endl; }
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		cout << dp[N][M] << endl;

	}
	return 0;
}
