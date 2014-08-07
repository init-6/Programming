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
typedef vector <LL> VLI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

VLI tree; 
int maxVal;

void update(int idx, int key)
{
	while(idx <= maxVal)
	{
		tree[idx] += key;
		idx += (idx & -idx);
	}
}


void buildBIT(int n)
{
	tree[0] = 0;
	int inp;
	FOR(i,1,n)
	{
		scanf("%d", &inp);
		update(i,inp);
	}
}

LL read(int idx)
{
	LL sum = 0;		
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N,Q;
		cin >> N;
		VLI ftree(N+1,0);
		tree = ftree;maxVal = N+1;
		buildBIT(N+1);
		cin >> Q;
		REP(i,Q)
		{
			int type;cin >> type;
			if(type == 0)
			{
				int l,r,k;cin >> l >> r >> k;
				vector <int> store;
				//LL ans = read(r+1) - read(l);
				FOR(i,l,r)
				{
					store.pb(read(i+1) - read(i));
				}
				sort(all(store));
				cout << store[k-1] << endl;
				REP(i,store.sz)
				cout << "stored " << store[i] << endl;
				
			}
			if(type == 1)
			{
				int idx,val;scanf("%d%d", &idx, &val);
				update(idx+1, val);
			}
		}
	}
	return 0;
}
