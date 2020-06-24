#include<stdio.h>
const int maxn=110;
int lenth(char str[])
{
    int i=0;
    do
    {
        i++;
    } while(str[i]!='\0');
    return i;
}
int main()
{
    char str1[maxn],str2[maxn];
    char str[220]="";
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        //printf("%s %s\n",str1,str2);
        int n1=lenth(str1);
        int n2=lenth(str2);
        //printf("%d %d\n",n1,n2);
        for(int i=0;i<n1;i++)
        {
            str[i]=str1[i];
        }
        int j=0;
        for(j=0;j<n2;j++)
        {
            str[n1+j]=str2[j];
        }
        str[j+n1]='\0';
        int n=lenth(str);
        //printf("%d %c %d\n",n,str[0],n);
        for(int i=0;i<n;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
