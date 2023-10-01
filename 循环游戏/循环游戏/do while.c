#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game()
{
	int i = 0;
	int ret = rand()%100+1;
	int n = 1;
	while (n <= 3)
	{
		printf("请输入数字：\n");
		scanf("%d", &i);
		if (i < ret)
		{
			printf("猜小了\n");
		}
		else if (i > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("正确\n");
			break;
		}
		n++;
	}
}
void moun()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}//定义一个选项函数；
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		moun();
		printf("请输入：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}