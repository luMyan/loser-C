#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void wasy(int *px,int *py)
{
	int z = 0;
	z = *px;
	*px = *py;
	*py = z;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d,%d", &a, &b);
	printf("交换前：a=%d,b=%d\n", a, b);
	wasy(&a, &b);
	printf("交换后：a=%d,b=%d\n", a, b);
	return 0;
}