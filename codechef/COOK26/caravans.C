#include <iostream>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		if(N==1)
		{
			int a;cin>>a;
			cout << "1" << endl;
			continue;
		}
		int a[N];
		for(int i=0;i<N;i++)
		cin >> a[i];


		int ans = 1;
		for(int i=1;i<N;i++)
		{
			if(a[i] <= a[i-1])
			ans++;
		}

		cout << ans << endl;
	}
	
	return 0;
}
