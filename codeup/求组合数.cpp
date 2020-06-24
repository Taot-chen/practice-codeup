#include<cstdio>
typedef long long ll;
ll c(ll m,ll n)
{
    ll res[70][70];
    if(n==0||n==m) return 1;
    if(res[m][n]!=0) return res[m][n];
    return res[m][n]=c(m-1,n-1)+c(m-1,n);
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
