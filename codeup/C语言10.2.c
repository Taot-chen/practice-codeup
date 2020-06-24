#include<stdio.h>
int main()
{
    int a, b,c;
    int *p1, *p2, *p3;
    p1=&a;
    p2=&b;
    p3=&c;
    scanf("%d%d%d",&a,&b,&c);
    if(*p1>*p3&&*p2<*p3)
    {
        int temp1=*p2;
        *p2=*p3;
        *p3=temp1;
    }
    else if(*p2>*p1&&*p1>*p3)
    {
        int temp2=*p1;
        *p1=*p2;
        *p2=temp2;
    }
    else if(*p2>*p3&&*p3>*p1)
    {
        int temp3=*p1;
        *p1=*p2;
        *p2=temp3;
        temp3=*p2;
        *p2=*p3;
        *p3=temp3;
    }
    else if(*p3>*p1&&*p1>*p2)
    {
         int temp4=*p1;
        *p1=*p3;
        *p3=temp4;
        temp4=*p2;
        *p2=*p3;
        *p3=temp4;
    }
    else if(*p3>*p2&&*p2>*p1)
    {
        int temp5=*p1;
        *p1=*p3;
        *p3=temp5;
    }
    printf("%d %d %d\n",*p1,*p2,*p3);
    return 0;
}
