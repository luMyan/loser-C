#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int arr[10] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("���������Ŀ�����������Խ���һ�����ڹر�\n");
	scanf("%s", arr);
	if (strcmp(arr,"���Ŀ�����") == 0)
	{
		system("shutdown -a");
		printf("ȡ���ػ�\n");
	}
	else
	{
		goto again;
	}
	return 0;
}