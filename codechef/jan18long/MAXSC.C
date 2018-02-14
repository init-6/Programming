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

#define GI ({int t;scanf("%d",&t);t;})
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
typedef vector <LL> VLI;
typedef vector <VI> VVI;
typedef vector <VLI> VVLI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		LL N; cin >> N;
		VVLI seq;
		REP(i, N)
		{
			VLI s(N, 0LL); REP(j, N) cin >> s[j];
			sort(all(s));
			seq.pb(s);
		}


		LL sum = seq[N-1][N-1], prev = seq[N-1][N-1];
		RREP(i, N-1)
		{
			int j = N - 1;
			while(j >= 0 && seq[i][j] >= prev) j--;	
			if(j < 0) { sum = -1LL; break;}
			sum += seq[i][j];
			prev = seq[i][j];
		}

		cout << sum << "\n";
	}
	return 0;
}
