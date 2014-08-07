// Stackoverflow question tryout
// http://stackoverflow.com/questions/16377895/console-output-keeps-crashing
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int i,j,n,t;

int main()
{
	cin>>t;

	while(t--)
	{
		vector <string> dr,rd;
		string a,b;
		cin>>n;
		cin.ignore();

		for(i=0;i<n;i++)
		{
			a.clear(),b.clear();
			getline(cin,a);
			j=a.find(" on ");
			b=a.substr(j,a.size()-1);
			a.resize(j);
			dr.push_back(a);
			rd.push_back(b);
		}

		for(i=0,j=rd.size()-1;i<rd.size();i++,j--)
		{
			cout<<dr[i]<<rd[j]<<endl;
		}
		cout<<endl;
	}

	return 0;
}
