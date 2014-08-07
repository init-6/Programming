#include<stdio.h>
int main()
{
	int x=7, y=9, z;
	z = x++ + ++y - x-- + --y;
	printf("%d",z);
	return 0;
}
