#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct S;
struct S
{
	char name[20];
	char sex[10];
	char tele[20];
	int age;
};
struct Q
{
	struct S s1;
	char num[20];
	float f;
};
void print(struct S* pp)
{
	printf("%s %s %s %d\n", pp->name, pp->sex, pp->tele, pp->age);
}
int main()
{
	struct S s1 = { "张三","男","13131313131",17 };
	struct Q q1 = { {"李四","女","33333333333",13},"保密",3.14f };
	printf("%s %s %s %d\n", s1.name, s1.sex, s1.tele, s1.age);
	printf("%s %s %s %d %s %f\n", q1.s1.name, q1.s1.sex, q1.s1.tele, q1.s1.age, q1.num, q1.f);
	print(&s1);
	
	return 0;
}