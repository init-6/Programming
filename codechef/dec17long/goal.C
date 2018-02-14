#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	
	while(cin >> s)
	{
		string teamA = "TEAM-A ", teamB = "TEAM-B ", tied = "TIE\n";
		
		int scoreA = 0, scoreB = 0;
		bool isWin = false;
		
		for(int i = 0; i < 10; ++i)
		{
			if(i&1) scoreB += (s[i] == '1');
			else scoreA += (s[i] == '1');
			
			
			if(i >= 6 && (abs(scoreA - scoreB)) >= 3)
			{
				isWin = true;
				scoreA > scoreB ? cout << teamA << i << "\n" : cout << teamB << i << "\n";
			}
			else if(i >= 7 && (abs(scoreA - scoreB)) >= 2)
			{
				isWin = true;
				scoreA > scoreB ? cout << teamA << i << "\n" : cout << teamB << i << "\n";
			}
			
			if(isWin) break;
		}
		
		if(scoreA == scoreB)
		{
			for(int i = 10; i < s.size(); ++i)
			{
				if(i&1) scoreB += (s[i] == '1');
				else scoreA += (s[i] == '1');
				
				if(!(i&1) && i > 10)
				{
					if(scoreA != scoreB)
					{
						scoreA > scoreB ? cout << teamA << i << "\n" : cout << teamB << i << "\n";
						isWin = true;
						break;
					}
				}
			}
		}
		
		if(!isWin)
		cout << tied;
		
		return 0;
	}
	
	return 0;
}