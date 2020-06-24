#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=110;
int n,m;
vector<int> adj[maxn];
int indegree[maxn];

bool topologicalsort()
{
    int num=0;
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
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            indegree[v]--;
            {
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        num++;
    }
    if(num==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int x,y;
    while(scanf("%d %d",&n,&m),n!=0)
    {
        fill(indegree,indegree+maxn,0);
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            indegree[y]++;
            adj[x].push_back(y);
        }
        bool res=topologicalsort();
        if(res)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
