#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
const int maxv=1010;
int dp[maxn];
int w[maxn],c[maxn];
int main()
{
    int v,n;
    while(scanf("%d %d",&v,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&w[i],&c[i]);
        }
        //fill(dp,dp+maxn,0);
        for(int i=0;i<=v;i++)
        {
            dp[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=v;j>=w[i];j--)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
            }
        }
        int res=-1;
        for(int i=0;i<=v;i++)
        {
            if(res<dp[i])
            {
                res=dp[i];
            }
        }
        printf("%d\n",res);
    }
}
