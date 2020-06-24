#include<cstdio>
int F(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else return F(n-1)+F(n-2);
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<2*n-2*j-2;k++)
            {
                printf(" ");
            }
            for(int k=0;k<2*j+1;k++)
            {
                printf("%d ",F(k));
            }
            printf("\n");
        }
    }
    return 0;
}
