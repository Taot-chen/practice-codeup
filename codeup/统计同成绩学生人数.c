#include<stdio.h>
int main()
{
    int maxn=1000;
    int a[maxn];
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int b,count=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&b);
        for(int i=0;i<n;i++)
        {
            if(a[i]==b)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
