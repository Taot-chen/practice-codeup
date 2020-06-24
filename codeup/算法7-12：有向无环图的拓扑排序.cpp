#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int maxn=55;
int G[maxn][maxn];
int n;
vector<int> ans;
int indegree[maxn];

bool topologicalsort()
{
    int num=0;
    stack<int> q;
    for(int i=0;i<n;i++)
    {
        if(!indegree[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.top();
        ans.push_back(u);
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(G[u][i])
            {
                indegree[i]--;
                {
                    if(!indegree[i])
                    {
                        q.push(i);
                    }
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
    while(scanf("%d",&n)!=EOF)
    {
        fill(indegree,indegree+maxn,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&G[i][j]);
                if(G[i][j])
                {
                    indegree[j]++;
                }
            }
        }
        bool res=topologicalsort();
        if(res)
        {
            for(int i=0;i<ans.size();i++)
            {
                printf("%d ",ans[i]);
            }
            printf("\n");
        }
        else
        {
            printf("ERROR\n");
        }
    }
    return 0;
}
