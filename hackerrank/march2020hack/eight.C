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
	while(T--)
	{
		string s; cin >> s;

		if(s[0] == '0' && s.sz == 1)
			cout << "YES" << endl;
		else if(s.sz == 1 && s[0] == '8')
			cout << "YES" << endl;
		else if(s.sz == 1 && s[0] != '8')
			cout << "NO" << endl;

		if(s.sz == 2)
		{
			int num1 = (s[0] - '0')*10 + (s[1] - '0');
			int num2 = (s[1] - '0')*10 + (s[0] - '0');

			if((num1 % 8) && (num2 % 8))
				cout << "NO" << endl;
			else cout << "YES" << endl;
		}

		if(s.sz >= 3)
		{
			int digits[111] = {0};
			int num = 0;
			bool flag = false;
			REP(i,s.sz)
			digits[i] = s[i]-'0';

			REP(i,s.sz)
			{
				REP(j,s.sz)
				{
					REP(k,s.sz)
					{
						if(i != k && i!= j && j != k)
						{
							num = digits[i]*100 + digits[j]*10 + digits[k];
							if(num % 8 == 0)
							{
								flag = true;
								break;
							}
						}
					}
					if(flag)
					break;
				}
				if(flag)
				break;
			}
			flag ? cout << "YES" << endl : cout << "NO" << endl;
		}
	}

	return 0;
}
