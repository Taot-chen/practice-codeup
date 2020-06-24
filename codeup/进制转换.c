#include<stdio.h>
#include<string.h>
char run(char str[])
{
    int div,pr=0;
    for(int i=0;i<strlen(str);i++)
    {
        div=((str[i]-'0')+pr*10)/2;
        pr=((str[i]-'0')+pr*10)%2;
        str[i]=div+'0';
    }
    return pr+'0';
}
int isempty(char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!='0')
        {
            return 0;
        }
    }
    if(i==strlen(str))
    {
        return 1;
    }
}
int main()
{
    char a[100];
    char result[100]="";
    while(scanf("%s",a)!=EOF)
    {
        int n=strlen(a);
        int m=0;
        do
        {
            result[m++]=run(a);
        } while(!isempty(a));
        result[m]='\0';
        for(int i=strlen(result)-1;i>=0;i--)
        {
            printf("%c",result[i]);
        }
        printf("\n");
    }
    return 0;
}
