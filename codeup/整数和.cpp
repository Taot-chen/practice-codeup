#include<cstdio>
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        if(n>0)
        {
            for(int j=n;j<=2*n;j++)
            {
                sum+=j;
            }
        }
        else
        {
            for(int j=2*n;j<=n;j++)
            {
                sum+=j;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
