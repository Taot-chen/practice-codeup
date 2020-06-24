#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1000010;
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
    int maxm=-1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n!=m)
        {
            a[n].push_back(m);
            a[m].push_back(n);
        }
        else
        {
            a[n].push_back(m);
        }
        maxm=maxm>n?maxm:n;
        maxm=maxm>m?maxm:m;
    }
    memset(flag,0,sizeof(flag));
    int cnt=0;
    for(int i=1;i<=maxm;i++)
    {
        if(flag[i]==false&&a[i].size()!=0)
        {
            cnt++;
            bfs(i);
        }
    }
    printf("%d\n",cnt);
    return 0;
}
