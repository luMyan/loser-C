#include <stdio.h>

int main()
{
    float a=8/2.5;
    int b=(int)3.14;
    int flag=0;
    int q=6;
    int x=q++;
    int arr[6]={1,2,3,4};
    int z=0;
    int s=10;
    int r=8;
    int u=10;
    int m=(r>u?r:u);
    if(z || s)
    {
        printf("hello,allen\n");
    }
    if(!flag)
    {
        printf("%d\n",flag);
    }
    printf("%.2f\n",a);
    printf("%d\n",b);
    printf("%d\n",q);
    printf("%d\n",x);
    printf("%d\n",sizeof(arr));
    printf("%d\n",m);
    return 0;
}
