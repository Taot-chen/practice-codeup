#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=10010;
int a[maxn],dp[maxn];
int main()
{
    string s;
    while(getline(cin,s))
    {
        LL n=1;
        LL sum=0;
        bool flag=false;
        fill(a,a+maxn,0);
        fill(dp,dp+maxn,0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                a[n]*=10;
                a[n]+=s[i]-'0';
            }
            else if(s[i]==' ')
            {
                sum+=a[n];
                n++;
            }
            else
            {
                flag=true;
                break;
            }
        }
        sum+=a[n];
        for (int i=1;i<=n;i++)
        {
            for(int j=sum/2;j>=a[i];j--)
                {
                    dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
                }
        }
        if(flag)
        {
            printf("ERROR\n");
        }
        else if(flag==false&&n!=1)
        {
            printf("%d %d\n",dp[sum/2],sum-dp[sum/2]);
        }

    }
    return 0;
}
