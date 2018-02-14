#include <bits/stdc++.h>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
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
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int go(string s)
{
	if(s.sz < 4) return 0;
	string c = "chef"; sort(all(c)); int ans = 0;
	do
	{
		FOR(i, 0, s.sz-3)
			if(s.substr(i, 4) == c) ans++;
	}
	while(next_permutation(all(c)));


	return ans;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		string yes = "lovely ", no = "normal";
		string s; cin >> s;

		int ans = go(s);
		ans ? cout << yes << ans : cout << no;
		cout << "\n";
	}
	return 0;
}
