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
		printf("���������֣�\n");
		scanf("%d", &i);
		if (i < ret)
		{
			printf("��С��\n");
		}
		else if (i > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ȷ\n");
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
}//����һ��ѡ�����
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		moun();
		printf("�����룺\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("������������������\n");
			break;
		}
	} while (input);
	return 0;
}