#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
char z[maxn],x[maxn];
int dp[maxn][maxn];
int main()
{
    while(scanf("%s %s",z+1,x+1)!=EOF)
    {
        int lenz=strlen(z+1);
        int lenx=strlen(x+1);
        for(int i=0;i<=lenz;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=lenx;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=lenz;i++)
        {
            for(int j=1;j<=lenx;j++)
            {
                if(z[i]==x[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[lenz][lenx]);
    }
    return 0;
}
