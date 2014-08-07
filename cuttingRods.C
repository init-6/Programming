#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int  main()
{
	int N;cin >> N;int price[N];
	int val[N+1];
	for(int i = 0;i<N;i++)
	cin >> price[i];

	val[0] = 0;

	for(int i = 1;i<=N;i++) {
		int maxv = 0;
		for(int j = 0;j<i;j++)
			maxv = max(maxv, price[j] + val[i-j-1]);
		val[i] = maxv;
	}

	cout << val[N] << endl;
	return 0;
}
