#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=30;
const int INF=0x3fffffff;
int G[maxn][maxn];
int d[maxn];
bool flag[maxn];
int n;

int prim()
{
    fill(d,d+maxn,INF);
    fill(flag,flag+maxn,false);
    d[1]=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        int MIN=INF;
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
        ans+=d[u];
        flag[u]=true;
        for(int v=1;v<=n;v++)
        {
            if(flag[v]==false&&d[v]>G[u][v]&&G[u][v]!=INF)
            {
                d[v]=G[u][v];
            }
        }
    }
    return ans;
}
int main()
{
    int k,w;
    char u,v;
    while(scanf("%d",&n),n!=0)
    {
        fill(G[0],G[0]+maxn*maxn,INF);

        for(int j=0;j<n-1;j++)
        {
            getchar();
            scanf("%c %d",&u,&k);
            for(int i=0;i<k;i++)
            {
                getchar();
                scanf("%c %d",&v,&w);
                int u1=u-'A'+1;
                int v1=v-'A'+1;
                G[u1][v1]=G[v1][u1]=w;
            }
        }
        int res=prim();
        printf("%d\n",res);
    }
    return 0;
}
