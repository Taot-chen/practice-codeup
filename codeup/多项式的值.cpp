#include<cstdio>
int f(int n,int a[],int x)
{
    int sum=0;
    for(int i=n;i>=0;i--)
    {
        sum=sum*x+a[i];
    }
    return sum;
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n+1];
        for(int i=0;i<n+1;i++)
        {
            scanf("%d",&a[i]);
        }
        int x;
        scanf("%d",&x);
        printf("%d\n",f(n,a,x));
    }
    return 0;
}
