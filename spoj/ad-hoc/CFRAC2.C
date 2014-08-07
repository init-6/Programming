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
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

ULL to_num(string s)
{
	ULL ret = 0;
	REP(i,s.sz)
	ret = 10*ret + (s[i] - '0');

	return ret;
}

int main()
{
	int n, m;
	while(cin >> n >> m && n && m)
	{
		vector <string> v(n, "");
		REP(i,n)
		cin >> v[i];

		ULL arr[n];
		REP(i,n)
		{
			string num;
			REP(j, m)
			{
				if(v[i][j] >= '0' && v[i][j] <= '9')
				num += v[i][j];
			}
			arr[i] = to_num(num);
		}
		
		ULL den = 1, num = 0;
		ULL carry = 1;
		for(int i = n-1; i >= 1; i-=2)
		{
			den = arr[i];
			num = arr[i-2];
			num = num*carry;
			num += den*arr[i-1];
			carry = den;
			arr[i-2] = num;
		}

		cout << num << " " << den << endl;


	}

	return 0;
}
