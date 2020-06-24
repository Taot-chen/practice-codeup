#include<stdio.h>
#include<string.h>
const int maxm=100;
//const int maxn=25;
int main()
{
    int m,n=25;
    //while(scanf("%d",&m)!=EOF)
    //{
    scanf("%d",&m);
        char s[m][n];
        int count=0;
        int limit;
        for(int i=1;i<m+1;i++)
        {
            scanf("%s",s[i]);
            count++;
            int min=count-4+1;
            if(min>=1)//当count>=4时，下限的表示
            {
                limit=min;
            }
            else limit=1;
            for(int j=count;j>=limit;j--)
            {
                if(j!=count)
                {
                    printf(" ");
                }
                printf("%d=%s",count-j+1,s[j]);
            }
            printf("\n");
        }
    //}
    return 0;
}
