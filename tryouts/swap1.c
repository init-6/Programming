#include <stdio.h>

void swap1(char **x, char **y)
{
	char *temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	char *a = "Hello", *b = "World";
	printf("%s ", a);
	printf("%s\n", b);
	
	swap1(&a,&b);

	printf("%s ", a);
	printf("%s\n", b);
	return 0;
}
