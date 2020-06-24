#include<stdio.h>
#include<string.h>
const int maxn=256;
int main()
{
    char str[maxn];
    while(scanf("%s",str)!=EOF)
    {
        int n=strlen(str);
        int i=0;
        for(i=0;i<=n/2;i++)
        {
            //printf("%d\n",i);
            if(str[i]!=str[n-1-i])
            {
                printf("NO\n");
                break;
            }
        }
        //printf("%d %d\n",n,i);
        if(i>=n/2)
        {
            printf("YES\n");
        }
    }
    return 0;
}
