#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<string.h>
int main()
{
	char password[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º");
		scanf("%s", password);
		if (strcmp(password, "abcdef") == 0)
		{
			printf("µÇÂ¼³É¹¦");
			break;
		}
		else
		{
			printf("ERROR\n");
		}
	}
	if (i == 3)
	{
		printf("ÍË³ö\n");
	}
	return 0;
}