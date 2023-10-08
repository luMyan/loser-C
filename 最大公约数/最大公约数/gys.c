#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	printf("%d\n", b);
	return 0;
}