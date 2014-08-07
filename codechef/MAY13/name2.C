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

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		string M,F;
		int l;
		cin >> M >> F;
		if (M.sz <= F.sz) 
		{
		//check if M is subseq of F
			l=0;
			REP(i,F.sz)
			{
				if(l < M.sz && F[i] == M[l])
				l++;
			}
			l == M.sz ? cout << "YES" << endl : cout << "NO" << endl;
		}
		else
		{
		//check if F is subseq of M
			l=0;
			REP(i,M.sz)
			{
				if(l < F.sz && M[i] == F[l])
				l++;
			}
			l == F.sz ? cout << "YES" << endl : cout << "NO" << endl;
		}
	}

	return 0;
}
