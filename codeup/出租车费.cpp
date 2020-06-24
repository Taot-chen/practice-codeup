#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        double cost=0;
        if(n<=4)
        {
            cost=10;
        }
        else if(n>4&&n<=8)
        {
            cost=10+2*(n-4);
        }
        else
        {
            cost=18*(n/8);
            n=n%8;
            if(n>4)
            {
                cost+=10+2*(n-4);
            }
            else
            {
                cost+=2.4*n;
            }
        }
        if(cost-int(cost)==0) printf("%.0f\n",cost);
        else printf("%.1f\n",cost);
    }
    return 0;
}
