#include <stdio.h>
//#include <conio.h>

int factorial(int n)
{
	int ret = 1;
	if(n==0) return 1;
	return n*factorial(n-1);
}

int main()
{
	//printf("Hello world\n");
	int n;
	scanf("%d",&n);
	int ans = factorial(n);
	printf("%d",ans);
//	getchar();
//	getchar();
	return 0;
}
