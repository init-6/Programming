#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int t;cin >> t;
	while(t--)
	{
		int N,K;cin >> N >> K;
		long long int sum=0;
		
		int a[N];
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
		}
		sort(a,a+N);
		reverse(a,a+N);
		int dSum=0, sSum=0;
		for(int i = 0;i < max(K, N-K);i++)
		dSum += a[i];
		for(int i = max(K, N-K); i < N ;i++)
		sSum += a[i];
		cout << dSum - sSum << endl;
		
	}
	return 0;
}
