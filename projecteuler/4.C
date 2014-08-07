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

set <LL> prod;

bool ispalin(string s)
{
	int start = 0, end = s.sz/2;
	REP(i, end)
	if(s[i] != s[s.sz-1-i])
	return false;

	return true;

}

void go()
{
	FOR(a, 100, 1000)
	FOR(b, 100, 1000)
	{
		LL num = a*b;
		string s; stringstream ss;
		ss << num; ss >> s;
		if(ispalin(s))
		prod.insert(num);
	}
}

int main()
{
	go();
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		for(set <LL> :: reverse_iterator it = prod.rbegin(); it != prod.rend(); ++it)
		if(*it < N)
		{
			cout << *it << endl;
			break;
		}
	}

	return 0;
}
