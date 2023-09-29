#include <stdio.h>
#include <string.h>
int test()
{
    int a=1;
    if(a==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int r=test();
    int num=5;
    if(5==num)
    {
        printf("hehe\n");
    }
    printf("%d\n",r);
    for(int i=1;i<=100;i++)
    if(i%2==1)
    {
        printf("%d\n",i);
    }
    int a=0;
    scanf("%d",&a);
    if(a%2==1)
    {
        printf("ÆæÊı\n");
    }
    else
        printf("NO\n");
    return 0;
}
