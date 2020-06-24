#include<stdio.h>
#include<string.h>
const int maxn=110;

int main()
{   char s[maxn],a[maxn],b[maxn];
    while(gets(s),gets(a),gets(b))
    {
        //puts(s);
        //puts(a);
        //puts(b);
        int ns=strlen(s);
        int na=strlen(a);
        int nb=strlen(b);
        char temp[110][110];

        //把s中的每个单词分开存入temp
        int j=0,k=0;
        for(int i=0;i<ns;i++)
        {
            if(s[i]!=' ')
            {

                temp[j][k]=s[i];
                k++;
            }
            else
                {
                    j++;
                    k=0;
                }
        }
        for(int i=0;i<=j;i++)
        {
            if(strcmp(temp[i],a))
            {
                printf("%s",temp[i]);
            }
            else
            {
                printf("%s",b);
            }
            if(i!=j)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
