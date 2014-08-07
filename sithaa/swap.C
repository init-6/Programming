#include <iostream>

using namespace std;

int swap1(int a, int b)
{
	a^= b^= a^= b;
	cout << a << " " << b << endl;
}

int swap2(int a, int b)
{
	a = a+b;
	b = a-b;
	a = a-b;
	cout << a << " " << b << endl;
}
int main()
{
	cout << "Enter 2 numbers " << endl;
	int a, b;
	cin >> a >> b;

	swap1(a,b);
	swap2(a,b);

	return 0;
}
