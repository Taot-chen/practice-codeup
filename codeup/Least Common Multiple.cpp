#include<cstdio>
const int maxm=1000;
int a[maxm];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    int d=gcd(a,b);
    //printf("%d\n",d);
    return a/d*b;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            a[maxm]={0};
            int m;
            scanf("%d",&m);
            for(int i=0;i<m;i++)
            {
                scanf("%d",&a[i]);
            }
            int res=a[0];
            for(int i=1;i<m;i++)
            {
                res=lcm(res,a[i]);
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
