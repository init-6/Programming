#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout << "a A is born" << endl;
		}
		~A()
		{
			cout << "a A is dead " << endl;
		}
};

int main()
{
	//A *a = new A;
	//delete a;
	A a;

	return 0;
}
