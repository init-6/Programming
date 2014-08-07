#include <vector>
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

using namespace std;

#define REPEAT(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) REPEAT(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
using namespace std;


int main()
{
	string M;
	int T;
	cin >> T >> M;
	string code = "abcdefghijklmnopqrstuvwxyz";
	string CODE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map <char,char> M1,M2;

	REP(i,code.sz)
	{
		M1[code[i]] = M[i];
		M2[CODE[i]] = M[i] - 32;
	}
	 		
	while(T--)
	{
		string inp;cin >> inp;
		string ans="";
		REP(i, inp.sz)
		{
			if(inp[i] >= 'a' && inp[i] <= 'z')
			ans+= M1[inp[i]];
			else if(inp[i] >= 'A' && inp[i] <= 'Z')
			ans+= M2[inp[i]];
			else if(inp[i] == '_')
			ans+= ' ';
			else ans+= inp[i];

		}
		cout << ans << endl;
	}
	return 0;
}
