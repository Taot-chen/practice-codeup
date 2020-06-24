#include<stdio.h>
#include<string.h>
int main()
{
    const int maxN=80;
    char str[maxN];
    //gets(str);
    while(scanf("%s",str)!=EOF)
    {
        int N,n1,n2,n3;
        N=strlen(str);
        n1=(N+2)/3;
        n3=n1;
        n2=N-n1-n3;
        for(int i=0;i<n1-1;i++)
        {
            printf("%c",str[i]);
            for(int j=0;j<n2;j++)
            {
                printf(" ");
            }
            printf("%c\n",str[N-1-i]);
        }
        for(int i=n1-1;i<n1+n2+1;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
        //printf("%d %d %d",N,n1,n3);
    }
    return 0;
}
