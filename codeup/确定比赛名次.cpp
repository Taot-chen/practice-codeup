#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
const int maxn=510;
vector<int> ans;
vector<int> adj[maxn];
int indegree[maxn];
bool topologicalsort()
{
    int num=0;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        ans.push_back(u);
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
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
    int p1,p2;
    while(scanf("%d %d",&n,&m),n!=0&&m!=0)
    {
        fill(indegree,indegree+maxn,0);
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&p1,&p2);
            indegree[p2]++;
            adj[p1].push_back(p2);
        }
        ans.clear();
        topologicalsort();
        for(int i=0;i<ans.size();i++)
        {
            printf("%d",ans[i]);
            if(i<ans.size()-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
