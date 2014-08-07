#include <stdio.h>

void swap2(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a = 5, b = 10;
	printf("%d ", a);
	printf("%d\n", b);
	
	swap2(a,b);

	printf("%d ", a);
	printf("%d\n", b);
	return 0;
}
