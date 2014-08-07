#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main()
{
	int T;cin >> T;
	while(T--)
	{
		int n;cin >> n;
		int v[n];

		int ans = 0;


		int sum = 0;
		int minm = INT_MAX;
		for(int i=0;i<n;i++)
		{
			cin >> v[i];
			sum+=v[i];
			minm = min(v[i],minm);
		}

		ans = sum - (n*minm);
		cout << ans << endl;
	}

	return 0;
}
