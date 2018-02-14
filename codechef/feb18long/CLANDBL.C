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
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;
 
int cdiv[1001][1001];
map <VI, pair <VI, int> > val;
VVI store;

int common(int u, int v)
{
	int g = __gcd(u, v);

	int count = 0;
	for(int i = 1; i <= sqrt(g); i++)
	if(g%i == 0)
	{
		if(i*i == g) count++;
		else count += 2;
	}

	return count;
}

void precompute()
{
	FOR(i, 1, 1001)
	{
		cdiv[i][i] = 0;
		FOR(j, i+1, 1001)
		{
			cdiv[i][j] = common(i, j);
			cdiv[j][i] = cdiv[i][j];
		}
		
		VI v(1001, 0); FOR(j, 1, 1001) v[j] = cdiv[i][j];
		store.pb(v);
	}

//	int arr[25] = {12, 1,11, 8,10,14,15,21, 7, 5,23,22, 2,24,17,13, 9,18, 3,25,20,16, 6, 4,19};
//	int arr[125] = {58,17,53,79,114,38,118,37,59,9,35,108,85,22,80,28,47,115,68,87,97,124,52,88,55,121,24,111,105,67,110,90,6,33,45,82,107,11,122,16,74,86,41,117,104,125,94,70,63,83,29,89,64,60,30,12,95,62,3,66,102,14,109,7,120,15,8,78,40,4,31,76,49,91,13,18,19,69,32,50,72,113,42,73,61,25,21,99,43,112,106,44,84,46,23,119,116,96,27,75,51,36,1,93,100,101,56,98,81,48,65,10,34,39,2,71,92,103,77,26,54,57,5,123,20};

//	FOR(i, 0, 125)
//	{
//		FOR(j, 0, 125)
//		cout << cdiv[arr[i]][arr[j]] << " ";
//		cout << "\n";
//	}
//	cout << "\n";
}

int main()
{
	precompute();
	int T; cin >> T;

	while(T--)
	{
		int N; cin >> N;

		VVI mat(N+1, VI(N+1, 0));
		FOR(i, 1, N+1) FOR(j, 1, N+1) 
			cin >> mat[i][j];

//		cout << "\n";
//		FOR(i, 1, N+1) 
//		{
//			FOR(j, 1, N+1) cout << cdiv[i][j] << " ";
//			cout << "\n";
//		}

		val.clear();
		REP(i, N)
		{
			VI cnt(1001, 0);
			FOR(j, 1, N+1) cnt[store[i][j]]++;

			//REP(j, N+1) cout << store[i][j] << " ";
			//cout << "\n";
			
			if(val.find(cnt) != val.end())
			{
				VI x = val[cnt].first;
				x.pb(i+1);
				val[cnt] = mkp(x, 0);
			}
			else
			{
				VI idx; idx.pb(i+1);
				val[cnt] = mkp(idx, 0);
			}
		}

//		EACH(it, val)
//		{
//			VI a = it->first;
//			cout << "Printing hash\n";
//			REP(i, 11) cout << a[i] << " ";
//			cout << "\n";
//			cout << "Printing values\n";
//			pair <VI, int> p = it->second;
//			REP(i, p.first.sz) cout << p.first[i] << " ";
//			cout << "\n";
//			cout << p.second << "\n";
//
//		}

		FOR(i, 1, N+1)
		{
			 VI cnt(1001, 0); FOR(j, 1, N+1) cnt[mat[i][j]]++;

			cout << val[cnt].first[val[cnt].second] << "\n";
			val[cnt] = mkp(val[cnt].first, val[cnt].second+1);

		//	if(val[cnt].second == val[cnt].first.sz) val[cnt] = mkp(val[cnt].first, 0);
			
		}


	}

	return 0;
}
