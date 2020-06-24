#include<cstdio>
int is7(int a)
{
    if(a%7!=0&&a%10!=7&&a/10!=7) return 1;
    else return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(is7(i))
            {
                sum+=i*i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
