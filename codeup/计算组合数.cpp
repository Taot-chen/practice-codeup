#include<cstdio>
typedef long long ll;
ll c(ll m,ll n)
{
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*(m-n+i)/i;
    }
    return ans;
}
int main()
{
    ll m,n;
    while(scanf("%lld%lld",&m,&n)!=EOF)
    {
        ll res=c(m,n);
        printf("%lld\n",res);
    }
    return 0;
}
