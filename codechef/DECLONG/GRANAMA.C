#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		map <char,int> Mr,Ms;
		string r,s;
		cin >> r >> s;
		
		for(int i=0;i<r.length();i++)
		{
			Mr[r[i]]++;
		}

		for(int i=0;i<s.length();i++)
		{
			Ms[s[i]]++;
		}

		bool chefNo = false;
		for(int i=0;i<r.length();i++)
		{
			if(Ms[r[i]] == 0)
			{
				chefNo = true;
				break;
			}
		}
		if(chefNo)
		{
			cout << "YES" << endl;
			continue;
		}
		bool freqSame1 = true, freqSame2 = true;
		for(int i = 0; i< r.length();i++)
		{
			if(Mr[r[i]] != Ms[r[i]])
			freqSame1 = false;
		}

		for(int i = 0; i< s.length();i++)
		{
			if(Ms[s[i]] != Mr[s[i]])
			freqSame2 = false;
		}


		if(r.length() == s.length() && freqSame1 && freqSame2)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
