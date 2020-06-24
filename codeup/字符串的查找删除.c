#include<stdio.h>
#include<string.h>
char de[1000];
char str[1000][1000],temp[1000][1000];
int main()
{
    gets(de);
    int m=0;
    int ld=strlen(de);
    while(gets(str[m++]))

    //把待查找字符串全部转换成小写
    for(int i=0;i<ld;i++)
    {
        if(de[i]>='A'&&de[i]<='Z')
        {
            de[i]+=32;
        }
    }

    for(int i=0;i<m;i++)
    {
        int n=strlen(str[i]);
        //把待处理字符串全部转换成小写
        for(int j=0;j<n;j++)
        {
            temp[i][j]=str[i][j];//用temp来存放原字符串
            if(str[i][j]>='A'&&str[i][j]<='Z')
            {
                str[i][j]+=32;
            }
        }

        //对比查找
        for(int j=0,k=0;j<n;)
        {
            if(str[i][j+k]==de[k])
            {
                k++;
                if(k==ld)
                {
                    j+=k;
                    k=0;
                }
            }
            else
            {
                if(str[i][j]!=' ')
                {
                    printf("%c",temp[i][j]);
                }
                j++;
                k=0;
            }
        }
        printf("\n");
    }
    return 0;
}
