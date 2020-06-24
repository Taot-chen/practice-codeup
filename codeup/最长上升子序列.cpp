#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int a[maxn];
int dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        //fill(dp,dp+maxn,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int res=-1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=1;
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>res)
            {
                res=dp[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
