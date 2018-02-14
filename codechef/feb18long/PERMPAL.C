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

int main()
{
	int T; cin >> T;
	while(T--)
	{
		string s; cin >> s;
		int cnt[26] = {0}; REP(i, s.sz) cnt[s[i] - 'a']++;
		int oc = 0; bool poss = true;

		REP(i, 26)
			if(cnt[i] & 1) oc++;
		
		poss = (s.sz % 2 == 0 && oc == 0) || (s.sz % 2 == 1 && oc == 1);
		if(!poss) { cout << "-1\n"; continue;}

		VI ans(s.sz, 0); int start = 0, end = s.sz-1;
		VI eans, oans;
		REP(i, 26)
		{
			if(cnt[i] == 0) continue;
			eans.clear();

			REP(j, s.sz)
			if(cnt[i] % 2 == 0)
			{
				if(s[j] == (char) (i + 'a'))
				{
					eans.pb(j+1);
				}
			}
			else if(cnt[i] % 2 == 1)
			{
				if(s[j] == (char) (i + 'a'))
				{
					oans.pb(j+1);
				}
			}
			if(eans.sz > 0)
			{
				int c = eans.sz; int k = 0; 
				while(c--) { if(c&1) ans[start++] = eans[k++]; else ans[end--] = eans[k++];}
			}
		}

		if(oc)
		{
			int m = 0;
			REP(i, ans.sz) if(!ans[i]) ans[i] = oans[m++];
			REP(i, s.sz) cout << ans[i] << " ";
			cout << "\n";
		}
		else
		{
			REP(i, s.sz) cout << ans[i] << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
