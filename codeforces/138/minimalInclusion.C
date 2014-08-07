#include <iostream>
#include <map>

using namespace std;

int main()
{
	map <int,bool> seen;
	int n,k;
	cin >> n >> k;
	int key, a[n];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		seen.insert(make_pair(a[i],false));
	}


	int count = 0;
	int l=0,r=0;
	for(int i=0;i<n;i++)
	{
		if(!seen[a[i]])
		{
			count++;
			seen[a[i]] = true;
		}
		if(count == k)
		{
			r=i;
			break;
		}
	}

	if(count != k)
	{
		cout << "-1 -1" << endl;
	}

	int newl=0;
	for(int i = 0;i<n;i++)
	{
		seen[i]=false;
	}
	if(count == k)
	{
		for(int i=r;i>l;i--)
		{
			if(!seen[a[i]])
			{
				count--;
				if(count == 0)
				{
					newl=i;
					break;
				}
				seen[a[i]] = true;
			}
		}
	}
	if(count != 0)
	{
		cout << "-1 -1" << endl;
		return 0;
	}

	cout << newl+1 << " " << r+1 << endl;

	return 0;
}
