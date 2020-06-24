#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
char a[maxn];
char b[maxn];
int dp[maxn][maxn];
int main()
{
    while(scanf("%s%s",a+1,b+1)!=EOF)
    {
        //gets(a+1);
        int lena=strlen(a+1);
        int lenb=strlen(b+1);
        for(int i=0;i<=lena;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<lenb;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                if(a[i]==b[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
