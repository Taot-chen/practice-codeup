#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i, n;
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(48<=str[i]&&str[i]<=57)
        {
            str[i]=str[i];
        }
        else if(65<=str[i]&&str[i]<=90)
        {
            str[i]=155-str[i];
        }
        else if(97<=str[i]&&str[i]<=122)
        {
            str[i]=219-str[i];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}
