#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	vector <int> V;
	int a;

	cin >> a;
	while(!cin.eof())
	{
		cin >> a;
		V.push_back(a);
	}
	for(int i = V.size()-1;i >= 0; i--)
	cout << sqrt(V[i]) << endl;
	return 0;
}
