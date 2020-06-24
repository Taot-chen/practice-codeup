#include<stdio.h>
int main()
{
    int maxn=1000;
    int a[maxn];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]%2)
            {
                count1++;
            }
            else count2++;
        }
        if(count1>count2)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
