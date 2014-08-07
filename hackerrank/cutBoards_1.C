#include<iostream>
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector < pair < long long int , int > > v;
const long long int MOD= 1e9 + 7;

int main()
{
	int t,i;
	long long int k,m,n,yi,xi,cost;
	scanf("%d",&t);
	while(t--)
	{
		cin >> m >> n;
		for(i=0;i<m-1;i++)
		{
			scanf("%lld",&k);
			v.push_back(make_pair(k,1));
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld",&k);
			v.push_back(make_pair(k,0));
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		yi=xi=1;
		cost=0;
		for(i=0;i<v.size();i++)
		{
			if(!v[i].second)
			{
				cost = ((cost % MOD) + ((v[i].first%MOD)*(xi%MOD))%MOD)%MOD;
				yi++;
			}
			else
			{
				cost = ((cost % MOD) + ((v[i].first%MOD)*(yi%MOD))%MOD) % MOD;
				xi++;
			}
		}
		printf("%lld\n",cost);
		v.erase(v.begin(),v.end());
	}
	return 0;
} 

