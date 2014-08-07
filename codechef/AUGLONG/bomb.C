#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int N;cin >> N;
		if(N==0) { cout << 0 << endl;continue;}
		string inp;cin >> inp;
		bool destroyed[N];
		int ans = 0;
		memset(destroyed, sizeof(destroyed), 0);
		if(N==1) if(inp[0] == '1') {cout << 0 << endl; continue;}
		if(N==1) if(inp[0] == '0') {cout << 1 << endl; continue;}
		if(N>=2) {
			if(inp[0] == '1') destroyed[0] = destroyed[1] = true;
			if(inp[N-1] == '1') destroyed[N-1] = destroyed[N-2] = true;
		}
		for(int i = 1; i < N-1;i++)
		{
			if(inp[i] == '1')
			destroyed[i-1] = destroyed[i] = destroyed[i+1] = true;
		}

		for(int i=0;i < N;i++)
		{
			if(!destroyed[i]) ans++;
		}

		cout << ans << endl;

	}
	return 0;
}
