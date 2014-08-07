#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;
	vector <int> v(N);
	for(int i=0;i<N;i++)
	v[i] = i+1;
	if (K==0)
	{
		for(int i=0;i<N-1;i++)
		cout << v[i] << " ";
		cout << v[N-1] << endl;
	}
	else if(K == N-1)
	{
		reverse(v.begin(),v.end());	
		for(int i=0;i<N-1;i++)
		cout << v[i] << " ";
		cout << v[N-1] << endl;
	}
	else
	{
		vector <int> :: iterator it1, it2;
		it1 = v.begin();
		it2 = v.begin()+K;
		int cnt = N;
		while(N--)
		{
			if(it1 != v.begin()+K)
			{
				cnt++;
				cout << *it1;
				it1++;
				if(cnt != N)
				cout << " ";
				else
				cout << endl;
			}
			if(it2 != v.end())
			{
				cnt++;
				cout << *it2;
				it2++;
				if(cnt != N)
				cout << " ";
				else
				cout << endl;
			}
			
		}

	}

	return 0;
}
