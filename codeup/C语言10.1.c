#include<stdio.h>
int main()
{
    int a, b;
    int *p1, *p2;
    p1=&a;
    p2=&b;
    scanf("%d%d",&a,&b);
    if(*p1<*p2)
    {
        int temp=*p1;
        *p1=*p2;
        *p2=temp;
    }
    printf("%d %d\n",*p1,*p2);
    return 0;
}
