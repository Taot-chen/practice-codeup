#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int a[maxn];
struct res
{
    int st,en;
    int sum;
}dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        dp[0].st=dp[0].en=0;
        dp[0].sum=a[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1].sum+a[i]<a[i])
            {
                dp[i].st=dp[i].en=i;
                dp[i].sum=a[i];
            }
            else
            {
                dp[i].st=dp[i-1].st;
                dp[i].en=i;
                dp[i].sum=dp[i-1].sum+a[i];
            }
        }
        int maxsum=-1;
        int u=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i].sum>maxsum)
            {
                maxsum=dp[i].sum;
                u=i;
            }
        }
        if(maxsum<0)
        {
            printf("0 %d %d\n",a[0],a[n-1]);
        }
        else
        {
            printf("%d %d %d\n",maxsum,a[dp[u].st],a[dp[u].en]);
        }
    }
    return 0;
}
