#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swapp(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void randomize(int a[])
{
	for(int i=9;i>0;i--)
	{
		srand(time(NULL));
		int n = rand() % (i+1);
		swapp(&a[i], &a[n]);
	}
}


int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	randomize(a);
	for(int i = 0;i<10;i++)
	cout << a[i] << " ";
	cout << endl;
}
