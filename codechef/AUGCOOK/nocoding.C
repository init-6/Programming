#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		string s;cin >> s;
		int len = s.length();
		int ans = 1 + len;
		if(len == 1) 
		{
			cout << "YES" << endl;
			continue;
		}
		for(int i = 1;i<len;i++)
		{
			if(s[i] - s[i-1] > 0) ans+=(s[i] - s[i-1]);
			else if (s[i] - s[i-1] < 0) ans+=(s[i]-s[i-1] + 26);
		//	cout << s[i] - s[i-1] << " " << ans << endl;
		}
		//cout << ans << endl;
		if(ans <= 11*len)
		cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
