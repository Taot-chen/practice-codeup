#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100],s2[100];
    int n=0,i,n1,n2,st1,st2;
    gets(s1);
    gets(s2);
    n1=strlen(s1);
    n2=strlen(s2);
    if(n1>=n2)
    {
        for(i=0;i<n2;i++)
        {
            if(s1[i]!=s2[i])
            {
                n=s1[i]-s2[i];
            break;
            }

        }
        printf("%d\n",n);
    }
    else
    {
        for(i=0;i<n1;i++)
        {
            if(s1[i]!=s2[i])
            {
                n=s1[i]-s2[i];
            break;
            }

        }
        printf("%d\n",n);
    }
    //puts(s1);
    //puts(s2);
    return 0;
}
