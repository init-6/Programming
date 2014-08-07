#include <iostream>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int G;
		cin >> G;
		for(int i=0;i<G;i++)
		{
			int I,N,Q;
			cin >> I >> N >> Q;
			if(I == 1)
			{
				if(N%2)
				{
					if(Q == 1)
					cout << N/2 << endl;
					else
					cout << (N/2) + 1 << endl;
				}
				else
				{
					cout << N/2 << endl;
				}
			}
			else if(I == 2)
			{
				if(N%2)
				{
					if(Q == 1)
					cout << (N/2) + 1 << endl;
					else
					cout << N/2 << endl;
				}
				else
				{
					cout << N/2 << endl;
				}
			}

		}
	}

	return 0;
}
