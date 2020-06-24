#include<stdio.h>
int main()
{
    int maxn=100;
    int a[maxn];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int count=-1;
        int b;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&b);
        for(int i=0;i<n;i++)
        {
            if(a[i]==b)
            {
                count=i;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
