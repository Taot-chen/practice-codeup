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

    //�Ѵ������ַ���ȫ��ת����Сд
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
        //�Ѵ������ַ���ȫ��ת����Сд
        for(int j=0;j<n;j++)
        {
            temp[i][j]=str[i][j];//��temp�����ԭ�ַ���
            if(str[i][j]>='A'&&str[i][j]<='Z')
            {
                str[i][j]+=32;
            }
        }

        //�ԱȲ���
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
