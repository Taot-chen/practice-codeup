#include <cstdio>
#include <cmath>
int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0)
        return 1;
    if(b*b-4*a*c<=0)
        return 1;
    else
    {
        double r1,r2;
        r1=(-b+sqrt(b*b-4*a*c))/(2*a);
        r2=(-b-sqrt(b*b-4*a*c))/(2*a);
        printf("r1=%7.2f\nr2=%7.2f",r1,r2);
    }
    return 0;
}
