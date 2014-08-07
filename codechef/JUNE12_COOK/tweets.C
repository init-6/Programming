#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tweets;int clicks;
	cin >> tweets >> clicks;

	int ans = 0;
	int cnt[tweets];
	for(int i=0;i<tweets;i++)
		cnt[i] = 0;
	while(clicks--)
	{
		string s;cin >> s;
		int num = 0;
		string cmd = s.substr(0,5);
		if(cmd == "CLICK")
		{
			cin >> num;
			if(cnt[num-1] == 0)
			cnt[num-1] = 1, ans++;
			else cnt[num-1] = 0,ans--;
		}
		else if(cmd == "CLOSE")
		{
			ans = 0;
			for(int i=0;i<tweets;i++)
				cnt[i] = 0;

		}
		cout << ans << endl;
	}
}
