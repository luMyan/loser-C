#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int feb(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = feb(n);
	printf("%d\n", ret);
	return 0;
}