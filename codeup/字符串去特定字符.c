#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    char c;
    while(gets(s))
    {
        scanf("%c",&c);
        int n=strlen(s);
        char str[200]="";
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=c)
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
        getchar();
        /*for(int i=0;i<n;i++)
        {
            if(s[i]!=c)
            {
                str[j++]=s[i];
            }
        }
        for(int i=0;i<j;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");*/
    }
    return 0;
}
