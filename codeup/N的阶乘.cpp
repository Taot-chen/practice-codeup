#include<cstdio>
#include<cstring>
const int maxn=3000;
struct bign
{
    int d[maxn];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign chang(char str[])
{
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++)
    {
        a.d[i]=str[a.len-1-i]-'0';
    }
    return a;
}
bign multi(bign a,int b)
{
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++)
    {
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0)
    {
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}
void print(bign a)
{
    for(int i=a.len-1;i>=0;i--)
    {
        printf("%d",a.d[i]);
    }
    printf("\n");
    //printf("%d\n",a.len);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bign res;
        if(n==0)
        {
            res.d[res.len++]=1;
        }
        else
        {
            res.d[res.len++]=1;
            for(int i=1;i<=n;i++)
            {
                res=multi(res,i);
            }
        }
        print(res);
    }
    return 0;
}
