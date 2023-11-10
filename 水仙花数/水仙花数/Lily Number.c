#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	
	
	for (int i = 10000; i <= 99999; i++)
	{
		int sum = 0;
		for (int j = 1; j <= 4; j++)
		{
			int k = (int)pow(10, j);
			sum = sum + (i % k) * (i / k);
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}