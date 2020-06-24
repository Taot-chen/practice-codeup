#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int a=i;
            while(a--)
            {
                printf(" ");
            }
            int b=n-i;
            while(b--)
            {
                printf("*");
                if(b)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for(int i=1;i<n;i++)
        {
            int c=n-i-1;
            while(c--)
            {
                printf(" ");
            }
            int d=i+1;
            while(d--)
            {
                printf("*");
                if(d)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
