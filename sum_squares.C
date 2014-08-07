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
	VI inp(N,0);
	int x;
	REP(i,N) { cin >> x;inp[i] = x;}

	sort(all(inp));
	vector < pair < int, pair <int, int> > > gen_pairs;

	REP(i,N)
	{
		FOR(j,i+1,N)
		{
			gen_pairs.pb(mkp(inp[i]*inp[i] + inp[j]*inp[j], mkp(i,j)));
		}
	}

	sort(all(gen_pairs));
	
	bool found = false;
	REP(i,gen_pairs.sz-1)
	{
		if(gen_pairs[i].first == gen_pairs[i+1].first)
		{
			int id_a = gen_pairs[i].second.first;
			int id_b = gen_pairs[i].second.second;
			int id_c = gen_pairs[i+1].second.first;
			int id_d = gen_pairs[i+1].second.second;
			if(id_a != id_c && id_a != id_d && id_b != id_c && id_b != id_d)
			{
				cout << "a : " << inp[gen_pairs[i].second.first] << " b : " << inp[gen_pairs[i].second.second] << " c : " << inp[gen_pairs[i+1].second.first] << " d : " << inp[gen_pairs[i+1].second.second] << endl;
				found = true;
				break;
			}
		}
	}
	if(!found) cout << "Not found" << endl;
	return 0;
}
