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
	int T; cin >> T;
	cin.ignore();
	while(T--)
	{
		string s;

		do
		{
			getline(cin, s);
		}
		while (s.sz == 0);

		stringstream ss;
		ss << s;

		string token;
		ss >> token;

		LL sum = 0;
		REP(i,token.sz)
		sum = 10*sum + (token[i]-'0');

		string a, b;
		while(ss >> a)
		{
			if(a == "=")
			break;
			if(a == "+")
			{
				ss >> b;
				LL num = 0;
				REP(i, b.sz)
				num = 10*num + (b[i] - '0');

				sum += num;
			}

			if(a == "-")
			{
				ss >> b;
				LL num = 0;
				REP(i, b.sz)
				num = 10*num + (b[i] - '0');

				sum -= num;
			}

			if(a == "*")
			{
				ss >> b;
				LL num = 0;
				REP(i, b.sz)
				num = 10*num + (b[i] - '0');

				sum *= num;
			}

			if(a == "/")
			{
				ss >> b;
				LL num = 0;
				REP(i, b.sz)
				num = 10*num + (b[i] - '0');

				sum /= num;
			}
		}
		cout << sum << endl;
	}
}
