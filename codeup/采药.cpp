#include<cstdio>
#include<algorithm>
using namespace std;
const int maxT=1010;
const int maxm=110;
int dp[maxT];
int w[maxT];
int v[maxT];
int main()
{
    int t,m;
    while(scanf("%d %d",&t,&m)!=EOF)
    {
        fill(dp,dp+maxT,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&v[i],&w[i]);
        }
        for(int i=0;i<m;i++)
        {
            for(int k=t;k>=v[i];k--)
            {
                dp[k]=max(dp[k],dp[k-v[i]]+w[i]);
            }
        }
        int res=0;
        for(int i=0;i<=t;i++)
        {
            if(res<dp[i])
            {
                res=dp[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
