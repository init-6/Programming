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
typedef unsigned long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		LL L[N];
		REP(i,N) cin >> L[i];
		LL A, B, C; cin >> A >> B >> C;
		string S;cin >> S;
		LL mul = 1, add = 0, pos = 0, rpos = N-1, idx = pos;
		REP(i,N)
		{
			if(S[i] == 'R')
			idx = (pos + rpos) - idx;
			if(S[i] == 'A')
			add = ((add % C) + (A % C)) % C;
			if(S[i] == 'M')
			{
				add = ((add % C) * (B % C)) % C;
				mul = ((mul % C) * (B % C)) % C;
			}

			LL val = ((((mul % C)*(L[idx] % C)) % C) + (add % C)) % C;
			if(i != N-1)
			cout << val << " ";
			else cout << val << endl;
			if(idx == pos)
			{idx++;pos++;}
			else {idx--;rpos--;}
		}
	}

	return 0;
}
