#include <stdio.h>

int main()
{
	int i = 0b1;
	i = i << 1;
	printf("%d\n", i);
//	i = i + 0b1;
	i = i << 1;
	i = i + 0b10;
	printf("%d\n",i);
}
