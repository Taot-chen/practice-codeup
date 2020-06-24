#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20], str2[20], str3[20];
    gets(str1);
    gets(str2);
    gets(str3);
    int cmp1=strcmp(str1,str2);
    int cmp2=strcmp(str1,str3);
    int cmp3=strcmp(str2,str3);
    int n1=strlen(str1);
    int n2=strlen(str2);
    int n3=strlen(str3);
    if(cmp1>0&&cmp3>0)
    {
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
    }
    else if(cmp2>0&&cmp3<0)
    {
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
    }
    else if(cmp1<0&&cmp2>0)
    {
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
    }
    else if(cmp3>0&&cmp2<0)
    {
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
    }
    else if(cmp2<0&&cmp1>0)
    {
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
    }
    else
    {
        for(int i=0;i<n1;i++)
        {
            printf("%c",*(str1+i));
        }
        printf("\n");
        for(int i=0;i<n2;i++)
        {
            printf("%c",*(str2+i));
        }
        printf("\n");
        for(int i=0;i<n3;i++)
        {
            printf("%c",*(str3+i));
        }
        printf("\n");
    }
    //printf("%d%d%d\n",cmp1,cmp2,cmp3);
    return 0;
}
