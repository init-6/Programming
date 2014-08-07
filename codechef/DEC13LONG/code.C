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
	int T;cin >> T;
	while(T--)
	{
		string english, cipher, enigma;
		cin >> english;
		cin.ignore();
		getline(cin, cipher);
		int freq1[26] = {0};
		set < pair < int, char > > S;
		REP(i,cipher.sz)
		{
			if(cipher[i] >= 'a' && cipher[i] <= 'z')
			freq1[cipher[i]-'a']++;
			else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
			freq1[cipher[i] - 'A']++;
		}

		enigma = "";

		REP(i,26)
		{
			S.insert(mkp(freq1[i], char (i + 'a')));
		}
		
		set <pair < int, char> > :: iterator it;

		for(it = S.begin(); it != S.end(); ++it)
		{
			enigma += it->second;
		}

		map <char, char> magic;

		REP(i,english.sz)
		{
			magic[enigma[i]] = english[i];
		}

		string ans = "";

		REP(i,cipher.sz)
		{
			if(cipher[i] >= 'a' && cipher[i] <= 'z')
			ans += magic[cipher[i]];
			else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
			ans += char (magic[cipher[i] - 'A' + 'a'] - 'a' + 'A');
			else ans += cipher[i];
		}
		cout << ans << endl;
	}
	return 0;
}
