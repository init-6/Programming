#include <iostream>

using namespace std;

int main()
{
	int a;
	while(cin >> a)
	(a&1) ? cout << (-(~a)) << endl : cout << a << endl;
	return 0;
}
