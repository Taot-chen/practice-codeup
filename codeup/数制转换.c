#include<stdio.h>
#include<string.h>
char run(char str[],int a,int b)
{
    int div,pr=0;
    for(int i=0;i<strlen(str);i++)
    {
        div=((str[i]-'0')+pr*a)/b;
        pr=((str[i]-'0')+pr*a)%b;
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
    int a,b;
    char n[100];
    char result[100]="";
    while(scanf("%d %s %d",&a,n,&b)!=EOF)
    {
        //printf("%d %s %d\n",a,n,b);

        //把a进制的n先转换成b进制
        int m=0;
        do
        {
            result[m++]=run(n,a,b);
        } while(!isempty(n));
        result[m]='\0';
        for(int i=strlen(result)-1;i>=0;i--)
        {
            printf("%c",result[i]);
        }
        printf("\n");
    }
    return 0;
}
