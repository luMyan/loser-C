#include <stdio.h>
void test()
{
    static int a=4;
    a++;
    printf("%d\n",a);
}
int main()
{
    int i=0;
    while(i<10)
    {
        test();
        i++;
    }
    return 0;
}
