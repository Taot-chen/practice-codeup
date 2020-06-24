#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=40;
int dp[maxn];
int F(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        dp[n]=F(n-1)+F(n-2);
        return dp[n];
    }

}
int main()
{
    int n;
    fill(dp,dp+maxn,-1);
    while(scanf("%d",&n)!=EOF)
    {
        int res=F(n);
        printf("%d\n",res);
    }
    return 0;
}
