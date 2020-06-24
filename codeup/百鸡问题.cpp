#include<cstdio>
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        int big=n/5,mid=n/3,sma=n*3;
        for(int x=0;x<=big;x++)
        {
            for(int y=0;y<=mid;y++)
            {
                for(int z=0;z<=sma;z++)
                {
                    double cost=5*x+3*y+z/3.0;
                    if(x+y+z==100&&cost<=n)
                    {
                        printf("x=%d,y=%d,z=%d\n",x,y,z);
                        //printf("%f\n",cost);
                    }
                }
            }
        }

    }
    return 0;
}
