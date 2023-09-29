#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1;
    while(i<=10)
    {
        i++;
        if(i==5)
            continue;
        printf("%d ",i);
    }
    printf("\n");
    char password[20]={0};

    printf("ÇëÊäÈëÃÜÂë£º");
    scanf("%s",password);
    getchar();
    printf("ÇëÈ·ÈÏÃÜÂë(Y/N)");
    int ch=getchar();
    if('Y'==ch)
    {
        printf("yes");
    }
    else printf("NO");
    return 0;
}
