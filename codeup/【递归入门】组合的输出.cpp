#include<cstdio>
void pri(int a[],int r)
{
    for(int i=1;i<=r;i++)
    {
        printf("%d",a[i]);
        if(i<r)
        {
            printf(" ");
        }
    }
    printf("\n");
}
bool f(int a[],int n,int r)
{
    if(a[r]<n)
    {
        a[r]++;
    }
    else
    {
        int i=1;
        while(a[r-i]==n-i&&r-i>0)
        {
            i++;
        }
        if(r==i)
        {
            return false;
        }
        a[r-i]++;
        while(i)
        {
            a[r-i+1]=a[r-i]+1;
            i--;
        }
    }
    return true;
}
int main()
{
    int a[100];
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        for(int i=1;i<=r;i++)
        {
            a[i]=i;
        }
        pri(a,r);
        while(f(a,n,r))
        {
            pri(a,r);
        }
    }
    return 0;
}
