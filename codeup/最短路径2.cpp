#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1010;
const int INF=0x3fffffff;
int n;
bool flag[maxn];
int d[maxn],G[maxn][maxn];
vector<int> pre[maxn],path,tempath;

struct node
{
    int v,w;
    node(int x,int y):v(x),w(y){};
};
vector<node> adj[maxn];
void dijkstra(int s)
{
    fill(d,d+maxn,INF);
    fill(flag,flag+maxn,false);
    d[s]=0;
    for(int i=1;i<=n;i++)
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
        for(int k=0;k<adj[u].size();k++)
        {
            int v=adj[u][k].v;
            if(flag[v]==false&&adj[u][k].w!=INF)
            {
                if(d[v]>adj[u][k].w+d[u])
                {
                    d[v]=adj[u][k].w+d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v]==adj[u][k].w+d[u])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

bool comp(vector<int> a,vector<int> b)
{
    int i=a.size()-1;
    int j=b.size()-1;
    while(i>=0&&j>=0)
    {
        if(a[i]!=b[j])
        {
            return a[i]<b[j];
        }
        i--;
        j--;
    }
    return a.size()<b.size();
}

void dfs(int v,int s)
{
    if(v==s)
    {
        tempath.push_back(v);
        if(path.size()==0)
        {
            path=tempath;
        }
        else if(comp(tempath,path))
        {
            path=tempath;
        }
        tempath.pop_back();
        return;
    }
    tempath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        dfs(pre[v][i],s);
    }
    tempath.pop_back();
}

int main()
{
    int m;
    int s,t;
    int a,b,dis;
    while(scanf("%d %d %d %d",&n,&m,&s,&t)!=EOF)
    {
        //fill(G[0],G[0]+maxn*maxn,INF);
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&dis);
            adj[a].push_back(node(b,dis));
            adj[b].push_back(node(a,dis));
        }
        dijkstra(s);
        if(d[t]==INF)
        {
            printf("can't arrive\n");
        }
        else
        {
            printf("%d\n",d[t]);
            tempath.clear();
            path.clear();
            dfs(t,s);
            for(int i=path.size()-1;i>=0;i--)
            {
                printf("%d%c",path[i],i>0?' ':'\n');
            }
        }
    }
    return 0;
}
