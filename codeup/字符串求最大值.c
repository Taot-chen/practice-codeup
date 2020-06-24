#include<stdio.h>
#include<string.h>
int main()
{
    int cmp1,cmp2;
    char str1[100],str2[100],str3[100],str[100];
    gets(str1);
    gets(str2);
    gets(str3);
    cmp1=strcmp(str1,str2);
    if(cmp1>0)
    {
        strcpy(str,str1);
    }
    else
    {
        strcpy(str,str2);
    }
    cmp2=strcmp(str,str3);
    if(cmp2>0)
    {
        strcpy(str,str);
    }
    else
    {
        strcpy(str,str3);
    }
    puts(str);
    return 0;
}
