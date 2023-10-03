#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int j = 0;

	for (j = 2; j <= n - 1; j++)
	{
		if (n % j == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i = 0;
	int count = 0;
	
	for (i = 101; i <= 200; i++)
	{
		if (prime(i))
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}