#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=30;
const int maxv=10010;
long long dp[maxv],v[maxn];
int main()
{
    int n,N;
    while(scanf("%d %d",&n,&N)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&v[i]);
        }
        fill(dp,dp+maxv,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=v[i];j<=N;j++)
            {
                dp[j]=dp[j]+dp[j-v[i]];
            }
        }
        printf("%lld\n",dp[N]);
    }
    return 0;
}
