#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T; cin >> T;
	
	while(T--)
	{
		int N, M; cin >> N >> M;
		
		vector <string> cake, ideal1, ideal2;
		
		for (int i = 0; i < N; ++i)
		{
			string s; cin >> s;
			cake.push_back(s);
		}
		
		string is1, is2;
		for(int i = 0; i < M; ++i) 
		{
			if(i&1) is1 += 'R';
			else is1 += 'G';
		}
		
		for(int i = 0; i < M; ++i) 
		{
			if(i&1) is2 += 'G';
			else is2 += 'R';
		}
		
		for(int i = 0; i < N; ++i) 
		{
			if(i&1) ideal1.push_back(is1), ideal2.push_back(is2);
			else ideal1.push_back(is2), ideal2.push_back(is1);
		}
		
		//for(int i = 0; i < N; ++i) cout << ideal1[i] << "\n";
		//for(int i = 0; i < N; ++i) cout << ideal2[i] << "\n";
		
		int cost1 = 0, cost2 = 0;
		
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				if(cake[i][j] == 'R' && ideal1[i][j] != 'R') cost1 += 5;
				if(cake[i][j] == 'G' && ideal1[i][j] != 'G') cost1 += 3;
				if(cake[i][j] == 'R' && ideal2[i][j] != 'R') cost2 += 5;
				if(cake[i][j] == 'G' && ideal2[i][j] != 'G') cost2 += 3;
			}
		}
		
		cout << min(cost1, cost2) << "\n";
	}
	
	return 0;
}