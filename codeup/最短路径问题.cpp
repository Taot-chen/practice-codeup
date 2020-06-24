#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1010;
const int maxm=100010;
const int INF=0x3fffffff;

int n,m;
int G[maxn][maxn],cost[maxn][maxn];
int d[maxn];
bool flag[maxn]={false};
int mincost=INF;
vector<int> pre[maxn];
vector<int> path,temppath;

void dijkstra(int s)
{
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        int MIN=INF;
        for(int j=1;j<=n;j++)
        {
            if(flag[j]==false&&d[j]<MIN)
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1)
        {
            return;
        }
        flag[u]=true;
        for(int v=1;v<=n;v++)
        {
            if(flag[v]==false&&G[u][v]!=INF)
            {
                if(d[v]>d[u]+G[u][v])
                {
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v]==d[u]+G[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v,int s)
{
    if(v==s)
    {
        temppath.push_back(v);
        int tempcost=0;
        for(int i=temppath.size()-1;i>0;i--)
        {
            int id=temppath[i],idnext=temppath[i-1];
            tempcost+=cost[id][idnext];
        }
        if(tempcost<mincost)
        {
            mincost=tempcost;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        dfs(pre[v][i],s);
    }
    temppath.pop_back();
}
int main()
{
    int s,t;
    while(scanf("%d%d",&n,&m),n!=0&&m!=0)
    {
        int u,v;
        fill(G[0],G[0]+maxn*maxn,INF);
        fill(cost[0],cost[0]+maxn*maxn,INF);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            scanf("%d%d",&G[u][v],&cost[u][v]);
            G[v][u]=G[u][v];
            cost[v][u]=cost[v][u];
        }
        scanf("%d%d",&s,&t);
        dijkstra(s);
        dfs(t,s);
        printf("%d %d\n",d[t],mincost);
    }
    return 0;
}
