#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int intCost(string cost)
{
	int len = cost.length();
	string ncost = cost.substr(0,len-1);
	stringstream ss;
	ss << ncost;
	int ret;ss >> ret;
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;cin >> N;
		string A,B;
		int sum = 0;
		map <  string, pair < string , string  > > dollars;
		map <string,int> M;
		for(int i = 0; i < N-1; i++)
		{
			string s1,s2,cost;
			cin >> s1 >> s2 >> cost;
			sum += intCost(cost);
			pair <string, string> P (s1,s2);
			dollars[s1] = pair < string, string> (s2, cost);
			M[s1]++;
			M[s2]++;
		}
		map <string, int> :: iterator it = M.begin();
		string _start, _end;

		for(it=M.begin();it != M.end();++it)
		{
			if((*it).second == 1)
			{ _start = (*it).first;break;}
		}

		for(it=M.begin();it != M.end();++it)
		{

			if((*it).second == 1 && (*it).first != _start)
			{ _end = (*it).first;break;}
		}


		
		map < string,  pair < string, string> > :: iterator itr = dollars.begin();
		bool yes = false;
		for(itr = dollars.begin();itr != dollars.end(); ++itr)
		{
			if((*itr).first == _start)
			yes = true;
		}
		if(!yes)
		swap(_start, _end);

		int count = N-1;
		while(count--)
		{
			cout << _start << " " << dollars[_start].first <<  " " << dollars[_start].second << endl;
			_start = dollars[_start].first;
		}
		cout << sum <<"$" << endl;
	}
	return 0;
}
