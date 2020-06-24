#include<stdio.h>
#include<math.h>
    int main ()
    {
        double a, b,c,r1,r2;
        double delt;
        scanf("%lf%lf%lf",&a,&b,&c);
        delt=b*b-4*a*c;
        if(a==0)
            printf("参数输入错误，a不可以为0\n");
        else if(delt<=0)
            printf("No real roots!\n");
        else
        {
            r1=(-b+sqrt(delt))/(2*a);
            r2=(-b-sqrt(delt))/(2*a);
            printf("r1=%7.2f\nr2=%7.2f",r1,r2);
        }

        return 0;
    }
