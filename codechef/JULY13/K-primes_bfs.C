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
typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;


const int MAX = 100000;
int main()
{

	int primes[MAX];
	memset(primes,0,sizeof(primes));

	bool isprime[100000];
	memset(isprime,1,sizeof(isprime));

	isprime[0] = isprime[1] = false;
	int n = sqrt(100000);

	//Sieve
	FOR(j,2,n+1)
	{
		if(isprime[j])
		{
			for(int k = j*j; k <= 100000; k += j)
			{
				isprime[k] = false;
			}
		}
	}

	queue <PI> Q;
	int cnt1 = 0, cnt2 = 0;
	vector <int> V1;
	vector <PI> V2;
	REP(i, sqrt(10000))
	{
		if(isprime[i])
		{
			Q.push(mkp(i,1));
			cout << i << endl;
//			V1[cnt1++] = i;
			V1.pb(i);
			cnt1++;
			//V2[cnt2++] = mkp(i,1);
			V2.pb(mkp(i,1));
		}
	}
	cout << cnt1 << endl;
	while(!Q.empty())
	{
		PI x = Q.front();
		if(x.first > 100)
		break;
		Q.pop();
		EACH(it,V1)
		{
			if(x.first*(*it) <= 100)
			{
				int e1,e2;
				e1 = x.first*(*it);
				e2 = (x.first % (*it) != 0) ? x.second++ : x.second;
				Q.push(mkp(e1,e2));
				//cout << e1 << " " << e2 << endl;
				V2.pb(mkp(e1,e2));
			}
		}

	}
	sort(all(V2));
	V2.erase(unique(V2.begin(), V2.end(), V2.end()));
	EACH(it,V2)
	cout << it->first << endl;

	int T;cin >> T;
	// Main loop
	while(T--)
	{
		int A,B,K;
		int ans = 0;
		cin >> A >> B >> K;
		EACH(it,V2)
		{
			if(it->second == K && it->first >= A && it->first <= B)
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
