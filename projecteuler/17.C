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

string ones[] = {"One", "Two", "Three", "Four", "Five", "Six" , "Seven", "Eight", "Nine"};
string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string except[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; 


int main()
{
	int T; cin >> T;
	while(T--)
	{
		string s; cin >> s;
		if(s == "0")
		{
			cout << "Zero\n";
			continue;
		}
		if(s.sz == 1)
		{
			cout << ones[s[0]-'1'] << "\n";
			continue;		
		}

		int tot = s.sz/3;
		int mod = s.sz%3;
		
		string root = "";
		if(tot == 0)
		{
			// Two digit numbers
			if(s[1] == '0')
			{
				cout << tens[s[0] - '1'] << "\n";
				continue;
			}
			if(s[0] == '1')
			{
				cout << except[s[1] - '1'] << "\n";
				continue;
			}
			cout << tens[s[0] - '1'] << " " << ones[s[1] - '1'] << "\n";
			continue;
			
		}

		if(tot == 1)
		{
			if(mod == 0)
			{
				string ans = "";
				// 3 digit
				ans = ones[s[0] - '1'] + " " + "Hundred" 

			}
		}
	}

	return 0;
}
