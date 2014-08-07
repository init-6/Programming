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
#define MAX 1000001

int main()
{
	int N;scanf("%d", &N);;
	VI keys(N,0);
	int sum;scanf("%d", &sum);
	VI leftmost(MAX,-1), rightmost(MAX,-1);

	int x;
	REP(i,N)
	{
		scanf("%d", &x);
		keys[i] = x;
		if(leftmost[keys[i]] == -1)
		{leftmost[keys[i]] = i;rightmost[keys[i]] = i;}
		else rightmost[keys[i]] = i;
	}

	VI clone(keys);
	sort(all(clone));

	int best = INT_MAX;
	REP(i,clone.sz)
	{
		if(clone[i] != sum - clone[i]) // distinct pairs
		{
			bool poss = binary_search(all(clone), sum - clone[i]);
			int ans = INT_MAX;
			if(poss)
			{
				best = min(best, max(leftmost[clone[i]]+1, leftmost[sum-clone[i]]+1));		
				best = min(best, max(N-rightmost[clone[i]], N-rightmost[sum-clone[i]]));
				best = min(best, max(leftmost[clone[i]]+1, N-rightmost[sum-clone[i]]));		
				best = min(best, max(N-rightmost[clone[i]], leftmost[sum-clone[i]]+1));		
			}
		}
	}
	
	best == INT_MAX ? cout << -1 << endl : cout << best << endl;

	return 0;
}
