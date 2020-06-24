#include<cstdio>
int main()
{
    double x,n;
    while(scanf("%lf%lf",&x,&n)!=EOF)
    {
        double y0=x;
        double y1;
        for(int i=0;i<n;i++)
        {
            y1=2.0*y0/3.0+x/(3*y0*y0);
            y0=y1;
        }
        printf("%.6f\n",y1);
    }
    return 0;
}
