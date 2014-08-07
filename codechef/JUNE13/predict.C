#include <iostream>

using namespace std;

int main()
{
	int T;cin >> T;
	while(T--)
	{
		double P, x1, x2, c;
		cin >> P;
		c = 1.0;
		x1 = (3-2*P)*P;
		x2 = (1 + 2*P)*(1-P);
		cout << fixed << max(max(x1,x2), c)*10000 << endl;
	}
	return 0;
}
