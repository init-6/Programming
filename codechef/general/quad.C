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

string h[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

int main()
{
	int N; cin >> N;
	string s; cin >> s;

	string upper="", lower="";
	REP(i, s.sz)
	{
		if(s[i] >= '0' && s[i] <= '9')
		upper += h[s[i]-'0'].substr(0,2), lower += h[s[i] - '0'].substr(2);
		else if(s[i] >= 'A' && s[i] <= 'F')
		upper += h[s[i]-'A'+10].substr(0,2), lower += h[s[i] - 'A' + 10].substr(2);
	}
	//cout << upper << " " << lower << endl;
	string sum = "";
	bool carry = false;
	for(int i = upper.sz-1; i >= 0; i--)
	{
		if(upper[i] == lower[i] && carry && upper[i] == '0')
		sum += '1', carry = false;
		else if(upper[i] == lower[i] && carry && upper[i] == '1')
		sum += '1';
		else if(upper[i] == lower[i] && upper[i] == '0')
		sum += '0';
		else if(upper[i] == lower[i] && upper[i] == '1')
		sum += '0', carry = true;
		else if(upper[i] != lower[i] && carry)
		sum += '0';
		else sum += '1';
	}

	reverse(all(sum));
	if(sum.sz <= 2*N)
	cout << sum << endl;
	else cout << sum.substr(sum.sz-2*N) << endl;
	return 0;
}
