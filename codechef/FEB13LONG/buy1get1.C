#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		map <char, int> M;
		for(int i=0;i<s.length();i++)
		{
			M[s[i]]++;
		}
		
		int ans=0;
		map <char, int> :: iterator it;
		for(it=M.begin(); it!= M.end(); it++)
		{
			if((it->second) % 2)
			ans += (it->second)/2 + 1;
			else ans += (it->second)/2;
		}

		cout << ans << endl;

	}
	
	return 0;
}
