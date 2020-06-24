#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
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
bign change(char str[])
{
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++)
    {
        a.d[i]=str[a.len-i-1]-'0';
        //printf("%d",a.d[i]);
    }
    //printf("\n");
    return a;
}
void trans(int a[],int n)
{
    //int temp;
    for(int i=0;i<n/2;i++)
    {
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-1-i]=temp;
    }
}
int main()
{
    char in[maxn];
    int temp[10*maxn]={0};
    int res[maxn]={0};
    while(scanf("%s",in)!=EOF)
    {
        bign a=change(in);
        int len=0;
        //int b=a.len;
        while(a.len>0)
        {
             int c=0;
            for(int i=a.len-1;i>=0;i--)
            {
                int q=(a.d[i]+10*c)/2;
                c=(a.d[i]+10*c)%2;
                a.d[i]=q;
            }
            temp[len++]=c;
            while(a.d[a.len-1]==0)
            {
                a.len--;
            }
        }
        /*for(int i=len-1;i>=0;i--)
        {
            printf("%d",temp[i]);
        }
        printf("\n");*/
        trans(temp,len);
        //int e=len;
        int num=0;
        while(len>0)
        {
            int f=0;
            for(int i=len-1;i>=0;i--)
            {
                int g=(temp[i]+2*f)/10;
                f=(temp[i]+2*f)%10;
                temp[i]=g;
            }
            res[num++]=f;
             while(temp[len-1]==0)
            {
                len--;
            }
        }
        for(int i=num-1;i>=0;i--)
        {
            printf("%d",res[i]);
        }
        printf("\n");
    }
    return 0;
}
