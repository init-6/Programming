#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string inp[T][T];
	int bit[T][T];
	bool flag[T][T];
	string S[T];
	for(int i = 0; i< T;i++)
	{
		for(int j = 0;j < T;j++)
		{
			cin >> inp[i][j];
			bit[i][j] = (inp[i][j] == "YES")? 1 : 0;	
		}
	}
	for(int i = 0;i<T;i++)
	{
		for(int j = 0;j<T;j++)
		{
			flag[i][j] = (bit[i][j] & bit[T-i][j]);
		}
	}
	for(int i = 0;i<T;i++)
	for(int j=0;j<T;j++)
	if(i==j)
	{
		flag[i][j]?cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
