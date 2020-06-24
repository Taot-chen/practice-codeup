#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
const int maxe=5010;

struct edge
{
    int u,v;
    int cost;
    int flag;
} E[maxe];

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

int kruskal(int n,int m)
{
    int ans=0;
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
            if(E[i].flag==0)
            {
                ans+=E[i].cost;
            }
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
    //int u,v,flag;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n*(n-1)/2;i++)
        {
            scanf("%d %d %d %d",&E[i].u,&E[i].v,&E[i].cost,&E[i].flag);
            if(E[i].flag==1)
            {
                E[i].cost=0;
            }
        }
        int res=kruskal(n,n*(n-1)/2);
        printf("%d\n",res);
    }
    return 0;
}
