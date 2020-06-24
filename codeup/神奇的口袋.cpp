#include<cstdio>
const int maxn=22;
int a[maxn];
int select(int sum,int n)
{
    if(sum==0) return 1;
    if(n==0) return 0;
    return select(sum-a[n],n-1)+select(sum,n-1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int result=select(40,n);
        printf("%d\n",result);
    }
    return 0;
}
