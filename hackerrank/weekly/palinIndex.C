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

bool check(string s)
{
	bool ret = true;
	REP(i, s.sz/2)
	{
		if(s[i] != s[s.sz - i - 1])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		if(s.sz == 1 || check(s))
		{
			cout << "-1" << endl;
			continue;
		}

		string poss1, poss2;
		int idx1 = 0, idx2 = 0;
		REP(i, s.sz/2)
		{
			if(s[i] != s[s.sz-i-1])
			{
				idx1 = i, idx2 = s.sz-i-1;
				break;
			}
		}
		poss1 = s.substr(0, idx1) + s.substr(idx1+1);
		poss2 = s.substr(0, idx2) + s.substr(idx2+1);
		//cout << poss1 << " " << poss2 << endl;
		if(check(poss1)) cout << idx1 << endl;
		else if(check(poss2)) cout << idx2 << endl;
		else cout << "-1" << endl;
	}

	return 0;
}
