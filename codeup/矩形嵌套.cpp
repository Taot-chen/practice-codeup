#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1010;
int dp[maxn];
int edge[maxn][2];
bool G[maxn][maxn];
int n;

int DP(int i)
{
    if(dp[i]>0)
    {
        return dp[i];
    }
    for(int j=0;j<n;j++)
    {
        if(G[i][j]==true)
        {
            int temp=DP(j)+G[i][j];
            if(temp>dp[i])
            {
                dp[i]=temp;
            }
        }
    }
    return dp[i];
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
        {
            int st=0;
            int a=0,b=0;
            memset(G,0,sizeof(G));
            fill(dp,dp+maxn,0);
            scanf("%d",&n);
            for(int j=0;j<n;j++)
            {
                scanf("%d %d",&edge[j][0],&edge[j][1]);
                if(edge[j][0]>edge[j][1])
                {
                    swap(edge[j][0],edge[j][1]);
                }
                if(edge[j][0]>a&&edge[j][1]>b)
                {
                    st=j;
                    a=edge[j][0];
                    b=edge[j][1];
                }
                for(int k=0;k<j;k++)
                {
                    if(edge[j][0]>edge[k][0]&&edge[j][1]>edge[k][1])
                    {
                        G[j][k]=true;
                    }
                    else if(edge[j][0]<edge[k][0]&&edge[j][1]<edge[k][1])
                    {
                        G[k][j]=true;
                    }
                }
            }
            int res=DP(st)+1;
            printf("%d\n",res);
        }
    }
    return 0;
}
