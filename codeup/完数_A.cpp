#include<cstdio>
bool iswan(int n)
{
    int a[1000]={0};
    int m=0,sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            a[m++]=i;
        }
    }
    for(int i=0;i<m;i++)
    {
        sum+=a[i];
    }
    if(sum==n) return true;
    else return false;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int wan[n]={0};
        int p=0;
        for(int i=2;i<=n;i++)
        {
            if(iswan(i)==true) wan[p++]=i;
        }
        if(p==0) printf("\n");
        else
        {
            for(int i=0;i<p;i++)
            {
                printf("%d",wan[i]);
                if(i<p-1) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
