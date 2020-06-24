#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
using namespace std;
const int maxn=25;
int indegree[maxn];
struct node
{
    int v,w;
    node(int _v,int _w):v(_v),w(_w){};
};
vector<node> adj[maxn];
vector<int> ans[maxn];
stack<int> topores;
int n,m;
int ve[maxn],vl[maxn];
char str[maxn];
map<char,int> mp;

bool topologicalsort()
{
    fill(ve,ve+maxn,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        topores.push(u);
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].v;
            int w=adj[u][i].w;
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
            if(ve[u]+w>ve[v])
            {
                ve[v]=ve[u]+w;
            }
        }
    }
    if(topores.size()==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int criticalpath()
{
    if(topologicalsort()==false)
    {
        return -1;
    }
    int keylength=0;
    for(int i=0;i<n;i++)
    {
        if(ve[i]>keylength)
        {
            keylength=ve[i];
        }
    }
    fill(vl,vl+maxn,keylength);
    while(!topores.empty())
    {
        int u=topores.top();
        topores.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].v;
            int w=adj[u][i].w;
            if(vl[v]-w<vl[u])
            {
                vl[u]=vl[v]-w;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans[i].clear();
        }
        for(int u=0;u<n;u++)
        {
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].v;
                int w=adj[u][i].w;
                int e=ve[u];
                int l=vl[v]-w;
                if(e==l)
                {
                    ans[u].push_back(v);
                }
            }
        }
    }
    int s;
        for(int i=0;i<n;i++)
        {
            if(ve[i]==0)
            {
                s=i;
                break;
            }
        }
        while(!ans[s].empty())
        {
            printf("(%c,%c) ",str[s],str[ans[s][0]]);
            s=ans[s][0];
        }
        return keylength;
}

int main()
{
    int N,w;
    char a,b;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[j].clear();
            }
            fill(indegree,indegree+maxn,0);
            scanf("%d %d",&n,&m);
            scanf("%s",str);
            mp.clear();
            for(int j=0;j<n;j++)
            {
                mp[str[j]]=j;
            }
            for(int j=0;j<m;j++)
            {
                getchar();
                scanf("%c %c %d",&a,&b,&w);
                adj[mp[a]].push_back(node(mp[b],w));
                indegree[mp[b]]++;
            }
            int res=criticalpath();
            printf("%d\n",res);
        }
    }
    return 0;
}
