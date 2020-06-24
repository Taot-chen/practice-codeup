#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000;
struct med
{
    double v;
    double c;
} wmed[maxn];
 bool cmp(med a,med b)
 {
     return a.c<b.c;
 }
int main()
{
    int p;
    while(scanf("%d",&p)!=EOF)
    {
        double v,w;
    int n;
    for(int i=0;i<p;i++)
    {
        scanf("%d",&n);
        scanf("%lf%lf",&v,&w);
        //w=w/100;
        double sw=0,sv=0;
        for(int j=0;j<n;j++)
        {
            wmed[j].v=v;
            scanf("%lf",&wmed[j].c);
            //wmed[j].c/=100;
        }
        sort(wmed,wmed+n,cmp);
        /*for(int k=0;k<n;k++)
        {
            printf("%f\n",wmed[k].c);
        }
        printf("%f\n",w);
        printf("%d\n",(w<wmed[0].c));*/
        if(w<wmed[0].c)
        {
            printf("0 0.00\n");
            break;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                sw+=wmed[j].c;
                if(sw/(i+1)<=w)
                {
                    sv+=wmed[j].v;
                }
                else
                {
                    sw=(sw-wmed[j].c)/j;
                    break;
                }
            }
            printf("%.0f %.2f\n",sv,sw/100);
        }
    }
    }

    return 0;
}
