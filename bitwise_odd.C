#include <iostream>

using namespace std;

int main()
{
	int n=10;
	int i=0;
	while(i<=n)
	{
		(i&1) ? cout << i << endl : cout << "I'm even\n";
		i++;
	}
	return 0;
}
