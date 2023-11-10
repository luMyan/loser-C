#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()    //指针加减整数
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (int i = 0; i < sz; i++)
//	{
//		*p++ = 1;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return (str - start);
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}