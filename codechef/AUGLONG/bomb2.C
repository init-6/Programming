#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		int ans = 0;
		if(N==0) { cout << ans << endl;continue;}
		string inp;cin >> inp;
		inp = '0'+inp+'0';
		for(int i = 1;i<inp.length()-1;i++)
		{
			if(inp[i] == '0' && inp[i-1] != '1' && inp[i+1] != '1')
			ans++;
		}

		cout << ans << endl;
	}
}
