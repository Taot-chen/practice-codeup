#include<cstdio>
bool iswan(int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(sum==n)
    {
        return true;
    }
    else return false;
}
bool isyin(int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(sum>n)
    {
        return true;
    }
    else return false;
}
int main()
{
    int e[60],g[60];
    int m=0,n=0;
    for(int i=2;i<=60;i++)
    {
        if(iswan(i))
        {
            e[m++]=i;
        }
        else if(isyin(i))
        {
            g[n++]=i;
        }
    }
    printf("E: ");
    for(int i=0;i<m;i++)
    {
        printf("%d ",e[i]);
    }
    printf("G: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",g[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
        else printf("\n");
    }
    return 0;
}
