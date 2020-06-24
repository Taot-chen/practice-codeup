#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
const int INF=0x3fffffff;

int n,G[maxn][maxn];
int d[maxn];
bool flag[maxn];

int prim()
{
    fill(d,d+maxn,INF);
    d[1]=0;
    fill(flag,flag+maxn,false);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++)
        {
            if(flag[j]==false&&d[j]<MIN)
            {
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1)
        {
            return -1;
        }
        flag[u]=true;
        ans+=d[u];
        for(int v=1;v<=n;v++)
        {
            if(flag[v]==false&&G[u][v]!=INF&&G[u][v]<d[v])
            {
                d[v]=G[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    int u,v,w;
    while(scanf("%d",&n),n!=0)
    {
        fill(G[0],G[0]+maxn*maxn,INF);
        for(int i=0;i<n*(n-1)/2;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u][v]=G[v][u]=w;
        }
        int res=prim();
        printf("%d\n",res);
    }
    return 0;
}
