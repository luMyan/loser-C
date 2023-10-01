#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int arr[10] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("请输入张心康是猪，否则电脑将在一分钟内关闭\n");
	scanf("%s", arr);
	if (strcmp(arr,"张心康是猪") == 0)
	{
		system("shutdown -a");
		printf("取消关机\n");
	}
	else
	{
		goto again;
	}
	return 0;
}