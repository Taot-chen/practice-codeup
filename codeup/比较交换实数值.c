#include<stdio.h>
int main ()
{
    double a, b, c, d;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a>b)
    {
        d=a;
        a=b;
        b=d;
    }
    if(a>c)
    {
        d=a;
        a=c;
        c=d;
    }
    if(b>c)
    {
        d=b;
        b=c;
        c=d;
    }
    printf("%.2f %.2f %.2f\n",a,b,c);
    return 0;
}
