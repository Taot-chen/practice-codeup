#include<stdio.h>
int main()
{
    int h;
    while(scanf("%d",&h)!=EOF)
    {
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<2*h-2*i-2;j++)
            {
                printf(" ");
            }
            for(int j=2*h-2*i-2;j<3*h-2;j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
