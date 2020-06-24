#include<cstdio>
#include<cstring>
struct bign
{
    int d[1010];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign change(char str[])
{
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++)
    {
        if(str[a.len-i-1]>='0'&&str[a.len-i-1]<='9')
        {
            a.d[i]=str[a.len-i-1]-'0';
        }
        else if(str[a.len-i-1]>='A'&&str[a.len-i-1]<='Z')
        {
            a.d[i]=str[a.len-i-1]-'A'+10;
        }
        //printf("%d",a.d[i]);
    }
    //printf("\n");
    return a;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        //printf("%d %d\n",m,n);
        char str[1010];
        scanf("%s",str);
        bign a;
        char res[1010];
        a=change(str);
        //for(int i=a.len-1;i>=0;i--)
        //{
        //    printf("%d",a.d[i]);
        //}
        //printf("\n");
        int num=0,c=0;
        int len=a.len;
        while(len)
        {
            for(int i=a.len-1;i>=0;i--)
            {
                int d=(a.d[i]+m*c)/n;
                c=(a.d[i]+m*c)%n;
                a.d[i]=d;
                if(c>=0&&c<=9)
                {
                    res[num++]=c+'0';
                }
                else if(c>=10&&c<36)
                {
                    res[num++]=c-10+'a';
                }
            }
            len--;
        }
        for(int i=num-1;i>=0;i--)
        {
            printf("%c",res[i]);
        }
        printf("\n");
    }
    return 0;
}
