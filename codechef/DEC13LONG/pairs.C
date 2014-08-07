#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
int main()
{
	int T;scanf("%d", &T);
	while(T--)
	{
		long long int ans = 0;
		int n; cin >> n;
		//vector <int> V(n);
		int inp;
		for(int i = 0; i < n ; ++i)
		{
			scanf("%d", &inp);
		//	V[i] = inp;
		}
		ans = (LL) ((LL)n * (LL)(n-1))/2;
		printf("%lld\n", ans);
	}
	return 0;
}
