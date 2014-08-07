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
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(long long int i=a;i<b;++i)
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

long long int Fair[100];
int main()
{
	int T;cin >> T;
	memset(Fair,0,sizeof(Fair));
	string s,rs;
	int size=0;
	REP(i,10000000)
	{	
		s = con(i);
		rs = s;
		reverse(s.begin(), s.end());
		if (s == rs)
		{
			string sqr,rsqr;
			sqr = con(i*i);
			rsqr = sqr;
			reverse(sqr.begin(),sqr.end());
			if(sqr == rsqr)
			{
				Fair[size++] = i*i;	
				cout << i << endl;
			}
		}
	}

	REP(c,T)
	{
		LL a,b;
		cin >> a >> b;
		int ans = 0;
		REP(k,size)
		{
			if(Fair[k] >= a && Fair[k] <= b)
			ans++;
		}

		cout << "Case #" << c+1 << ": " << ans << endl;
	}

	return 0;
}
