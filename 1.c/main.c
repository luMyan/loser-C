#include <stdio.h>

int Add(int x,int y)
{
    int z;
    z=x+y;
    return z;
}
int main()
{
    int n1;
    int n2;
    scanf("%d %d",&n1,&n2);
    int sum=Add(n1,n2);
    printf("%d\n",sum);
    return 0;
}
