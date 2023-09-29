#include <stdio.h>
#include <string.h>
void test()
{
    static int a=1;
    a++;
    printf("%d ",a);
}
 int main()
{
   int m=printf("Hello world!");
   printf("\n%d\n",m);

   int n=0;
   while(n<10)
   {
        test();
        n++;
   }
   printf("\n");
   int i=0;
   int r=0;
   int max=0;
   while(i<4)
   {
       scanf("%d",&r);
       if(r>max)
       {
           max=r;
           i++;
       }
   }
   printf("%d\n",max);
   return 0;
}
