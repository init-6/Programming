#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector <pair <int, string > > recipes;
	string s;int priority;
	while(N--)
	{
		cin >> s;cin >> priority;
		recipes.push_back(make_pair(priority, s));
	}

	sort(recipes.begin(), recipes.end());
	reverse(recipes.begin(), recipes.end());

	int nQ;cin >> nQ;
	while(nQ--)
	{
		string toFind;cin >> toFind;
		vector <pair <int, string> > :: iterator it;
		bool found = false;
		for(it = recipes.begin();it!=recipes.end();++it)
		{
			if(it->second.substr(0,toFind.length()) == toFind)
			{
				found = true,cout << it->second << endl;
				break;
			}
		}
		if(!found)
			cout << "NO" << endl;
	}

	
	return 0;
}
