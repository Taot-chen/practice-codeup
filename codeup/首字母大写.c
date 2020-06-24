#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    while(gets(str))
    {
        //puts(str);
        int n=strlen(str);
        //printf("%d\n",n);
        int i=0;
        do
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                str[i]=str[i]-32;
            }
            for(i++;str[i]!=' '&&str[i]!='\t'&&str[i]!='\r'&&str[i]!='\n';i++);
            i++;
        } while(str[i]!='\0');
        for(int j=0;j<n;j++)
        {
            printf("%c",str[j]);
        }
        printf("\n");
    }
    return 0;
}
