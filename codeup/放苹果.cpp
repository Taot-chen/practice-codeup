#include<cstdio>
const int maxn=20;
int dp[maxn][maxn];
int main()
{
    int k,a,b;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            scanf("%d %d",&a,&b);
            for(int j=0;j<=a;j++)
            {
                dp[j][0]=0;
                dp[j][1]=1;
            }
            for(int j=0;j<=b;j++)
            {
                dp[0][j]=1;
            }
            for(int j=1;j<=a;j++)
            {
                for(int k=1;k<=b;k++)
                {
                    if(j<k)
                    {
                        dp[j][k]=dp[j][j];
                    }
                    else
                    {
                        dp[j][k]=dp[j-k][k]+dp[j][k-1];
                    }
                }
            }
            int res=dp[a][b];
            printf("%d\n",res);
        }
    }
    return 0;
}
