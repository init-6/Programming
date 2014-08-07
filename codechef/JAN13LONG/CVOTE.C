#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n,m;
	cin >>n >>m;
	map <string, string> list;
	string chef, country;
	for(int i=0;i<n;i++)
	{
		cin >> chef >> country;
		list[chef] = country;
	}
	map<string, int> chef_votes, country_votes;
	map <string, int> :: iterator it;
	string vote;
	for(int i=0;i<m;i++)
	{
		cin >> vote;
		chef_votes[vote]++;
		country_votes[list[vote]]++;
	}
	string countryans, chefans;
	int maxvotes = -1;
	for(it= chef_votes.begin();it!= chef_votes.end();++it)
	{
		if(maxvotes < it->second)
		{
			maxvotes = it->second;
			chefans = it->first;
		}
	}

	maxvotes = -1;
	for(it= country_votes.begin();it!= country_votes.end();++it)
	{
		if(maxvotes < it->second)
		{
			maxvotes = it->second;
			countryans = it->first;
		}
	}

	cout << countryans << endl << chefans << endl;
	return 0;
}
