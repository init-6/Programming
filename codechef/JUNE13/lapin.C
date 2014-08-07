#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		string s;cin >> s;
		int len = s.size();
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i < (len/2);i++)
		{
			cnt[s[i] - 'a']++;			
		}
		int half = 0;
		if (len & 1)
			half = len/2+1;
		else half = len/2;
		for(int i=half; i < len;i++)
		{
			cnt[s[i] - 'a']--;
		}
		bool flag = true;
		for(int i = 0; i < 26; i++)
		{
			if ( cnt[i] != 0)
			{
				flag = false;
				cout << "NO" << endl;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;

	}
	return 0;
}
