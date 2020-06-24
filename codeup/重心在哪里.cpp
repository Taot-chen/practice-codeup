#include<cstdio>
#include<utility>
using namespace std;
int main()
{
    pair<double,double>a,b,c,res;
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf %lf %lf",&a.first,&a.second,&b.first,&b.second,&c.first,&c.second);
            res.first=(a.first+b.first+c.first)/3;
            res.second=(a.second+b.second+c.second)/3;
            printf("%.1f %.1f\n",res.first,res.second);
        }
    }
    return 0;
}
