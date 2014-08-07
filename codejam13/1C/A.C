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

int substrCount( const std::string & str, const std::string & obj ) {
	int n = 0;
	std::string ::size_type pos = 0;
	while( (pos = obj.find( str, pos )) 
			!= std::string::npos ) {
		n++;
		pos += str.size();
	}
	return n;
}

int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		string s;int N;
		cin >> s >> N;
		string inp;
		REP(i,s.sz)
		{
			if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'u' && s[i] != 'o')
			inp += '1';
			else inp += '0';
		}

		string gen;
		REP(i,N)
		gen += '1';
		
		// count the number of substrings
		int count = substrCount(gen, inp);

		cout << "Case #" << c+1 << ": " << endl;
	}

	return 0;
}
