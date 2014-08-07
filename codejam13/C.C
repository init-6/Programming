#include <vector>
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

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define len length()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef pair<int, int> PI;

string con(int n){
	stringstream ss;
	string s;
	ss<<n;
	s = ss.str();
	return s;
}

bool pal[1001];
bool sqpal[32];
bool square[1001];
int main()
{
	int T;cin >> T;
	string s,rs;
	REP(i,1001)
	pal[i] = false;
	REP(i,1001)
	{	
		s = con(i);
		rs = s;
		reverse(s.begin(), s.end());
		if (s == rs)
		pal[i] = true;
		square[i] = false;
	}

	REP(k,32)
	{
		if(pal[k*k])
		{
			sqpal[k] = true;
		}
	}

	REP(i,32)
	{
		square[i*i] =true;
	}

	REP(c,T)
	{
		int a,b;
		cin >> a >> b;
		int ans = 0;
		for(int i=a;i <= b; i++)
		{
			if(square[i])
			{
				if(sqpal[(int) sqrt(i)] && pal[(int) sqrt(i)])
				{
					ans++;
					//cout << i << endl;
				}
			}
		}


		cout << "Case #" << c+1 << ": " << ans << endl;
	}

	return 0;
}
