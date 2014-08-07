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
 	int N,P,K;
	cin >> N >> P >> K;

	string end = ">>";
	string begin = "<<";
	int start = P-K, finish = P+K+1;

	if(P-K <= 1) {begin = "", start = 1;}
	if(P+K >= N) {end = "", finish = N+1;}

	string ans = begin;
	if(begin.sz > 1)
	cout << begin << " ";
	FOR(i, start, finish)
	{
		if(i == P)
		cout << "(" << i << ")" << " ";	
		else cout << i << " ";
	}
	cout << end << endl;

	return 0;
 }
