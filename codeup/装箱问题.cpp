#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=20010;
const int maxv=20010;
int dp[maxn];
int v[maxn];
int main()
{
    int n,V;
    int temp;
    while(scanf("%d %d",&V,&n)!=EOF)
    {
        if(!n)
        {
            printf("%d\n",V);
        }
        else
        {
            fill(dp,dp+maxn,V);
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&temp);
                v[i]=temp;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=V;j>=v[i];j--)
                {
                    dp[j]=min(dp[j],dp[j-v[i]]-v[i]);
                }
            }
            int res=dp[0];
            for(int i=1;i<=V;i++)
            {
                if(res>dp[i])
                {
                    res=dp[i];
                }
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
