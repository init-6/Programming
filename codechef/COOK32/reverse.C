#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T,N,P,Q;
	cin >> T;
	while(T--)
	{
		cin >> N >> P >> Q;
		vector <int> v;
			for(int i=0;i<N;i++)
			{
				if(i == P-1)
				v.push_back(1);
				else
				v.push_back(0);
			}
		int L,R;
		while(Q--)
		{
			cin >> L >> R;
			reverse(v.begin()+(L-1), v.begin()+(R));
		}
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(v[i])
			{
				ans = i+1;
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
