#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=110;
const int maxe=10010;

struct edge
{
    int u,v;
    double cost;
}E[maxe];

bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}

int father[maxn];
int findfather(int x)
{
    int a=x;
    while(a!=father[a])
    {
        a=father[a];
    }
    while(x!=father[x])
    {
        int z=x;
        x=father[x];
        father[z]=a;
    }
    return a;
}

double kruskal(int n,int m)
{
    double ans=0.0;
    int num_edge=0;
    for(int i=0;i<n;i++)
    {
        father[i]=i;
    }
    sort(E,E+m,cmp);
    for(int i=0;i<m;i++)
    {
        int fau=findfather(E[i].u);
        int fav=findfather(E[i].v);
        if(fau!=fav)
        {
            father[fau]=fav;
            ans+=E[i].cost;
            num_edge++;
            if(num_edge==n-1)
            {
                break;
            }
        }
    }
    if(num_edge!=n-1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    int n;
    double x[maxn]={0.0};
    double y[maxn]={0.0};
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }
        int p=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                E[p].u=i;
                E[p].v=j;
                E[p].cost=w;
                p++;
            }
        }

        double res=(int)(kruskal(n,n*n)*100+0.3)/100.0;
        printf("%.2f\n",res);
    }
    return 0;
}
