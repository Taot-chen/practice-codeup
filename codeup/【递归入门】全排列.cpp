#include<cstdio>
int n;
bool flag[100]={false};
int ans[100];
void f(int m)
{
    if(m==n)//递归边界
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        if(flag[i]==false)
        {
            ans[m]=i+1;
            flag[i]=true;
            f(m+1);
            flag[i]=false;
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int m=0;
        f(m);
    }
    return 0;
}
