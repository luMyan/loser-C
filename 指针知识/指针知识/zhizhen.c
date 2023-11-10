#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	/*int a = 33;
	int b = 29;
	int c = 21;
	int arr[10];
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* parr[10] = { &a,&b,&c };
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", parr[i]);
	}*/
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 4,5,6,7 };
	int* arr[3] = { arr1,arr2,arr3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}