#include<stdio.h>
#include<string.h>
const int maxn=210;
int main()
{
    char str[maxn];
    while(gets(str))
    {
        int n=strlen(str);
        for(int i=n-1;i>=0;i--)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
