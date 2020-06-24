#include<stdio.h>
#include<string.h>
int main()
{
    int maxn=100;
    int a[maxn];
    memset(a,0,sizeof(a));
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int maxm=n-1;
        int b[maxm];
        memset(b,0,sizeof(b));
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }

        for(int i=0;i<m;i++)
        {
            int j=0;
            for(j=0;j<n;j++)
            {
                if(b[i]==a[j])
                {
                    printf("YES\n");
                    break;
                }

            }
            if(j==n)
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
