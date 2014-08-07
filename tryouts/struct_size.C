#include <iostream>

using namespace std;

struct mystruct
{
	int a;
	char c;
};


int main()
{
	mystruct a;
	cout << sizeof(a) << endl;
	return 0;
}
