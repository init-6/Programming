#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

int main()
{
	int T;cin>>T;
	while(T--)
	{
		int N;cin >> N;
		double sum = 0;
		int cases = 1;
		double points[N];
		for(int i=0;i<N;i++)
		{
			cin >> points[i];
			sum += points[i];
		}
		
		double ans = 0.0;
		cout << "Case #" << cases << ":";
		for(int i = 0;i<N;i++)
		{
			ans = (2/(double) N) - (points[i]/sum);
			ans*= 100.0;
			printf("%0.6lf", ans);
			cout << " ";
			ans = 0;
		}
		cout << endl;
		
		cases++;
	}
}
