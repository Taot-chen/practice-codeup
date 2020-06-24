#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
bool flag[maxn]={false};
vector<int> a[maxn];
void bfs(int n)
{
    flag[n]=true;
    for(int i=0;i<a[n].size();i++)
    {
        int m=a[n][i];
        if(flag[m]==false)
        {
            bfs(m);
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n!=0)
    {
        int x,y;
        int maxm=-1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
            maxm=maxm>x?maxm:x;
            maxm=maxm>y?maxm:y;
        }
        int cnt=0;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<maxm;i++)
        {
            if(flag[i]==false&&a[i].size()!=0)
            {
                cnt++;
                bfs(i);
            }
        }
        if(cnt==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        for(int i=0;i<maxm;i++)
        {
            a[i].clear();
        }
    }
    return 0;
}
