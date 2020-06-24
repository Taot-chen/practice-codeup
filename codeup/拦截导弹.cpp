#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=30;
int a[maxn];
int dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        fill(dp,dp+maxn,1);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]<=a[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int res=-1;
        for(int i=0;i<n;i++)
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
