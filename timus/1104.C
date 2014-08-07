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
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	string s;
	cin >> s;
	
	sort(all(s));
	int sum = 0, base = 0;

	REP(i,s.sz)
	{
		if(s[i] >= '0' && s[i] <= '9') sum += (s[i] - '0'), base = (s[i] - '0');
		else sum += (s[i] - 'A'+10), base = (s[i] - 'A'+10);
	}
	if(base < 2) 
	{
		cout << "2" << endl;
		return 0;
	}

	bool found = false;
	FOR(i,base+1,37)
	{
		if(sum % (i-1) == 0)
		{
			found = true;
			cout << i << endl;
			break;
		}
	}

	if(!found) cout << "No solution." << endl;
	return 0;
}
