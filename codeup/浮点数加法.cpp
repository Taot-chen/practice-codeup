#include<cstdio>
#include<cstring>
const int maxn=110;
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
void chang(char str[],bign &a,bign &b)
{
    int len=strlen(str);
    int m=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='.') break;
        else m++;
    }
    for(int i=m-1;i>=0;i--)
    {
        a.d[a.len++]=str[i]-'0';
    }
    /*for(int i=a.len-1;i>=0;i--)
    {
        printf("%d",a.d[i]);
    }
    printf("\n");*/
    for(int i=len-1;i>=m+1;i--)
    {
        b.d[b.len++]=str[i]-'0';
    }
    /*for(int i=b.len-1;i>=0;i--)
    {
        printf("%d",b.d[i]);
    }
    printf("\n");*/
    //printf("%d\n",b.len);
}
int add1(bign a,bign b,bign &carr)
{
    if(a.len<b.len)
    {
        int s[maxn];
        for(int i=0;i<a.len;i++)
        {
            s[i]=a.d[a.len-1-i];
        }
        for(int i=0;i<a.len;i++)
        {
            a.d[i]=s[i];
        }
        for(int i=a.len;i<b.len;i++)
        {
            a.d[i]=0;
            a.len++;
        }
        for(int i=0;i<a.len;i++)
        {
            s[i]=a.d[a.len-1-i];
        }
        for(int i=0;i<a.len;i++)
        {
            a.d[i]=s[i];
        }
    }
    else
    {
        int s[maxn];
        for(int i=0;i<b.len;i++)
        {
            s[i]=b.d[b.len-1-i];
        }
        for(int i=0;i<b.len;i++)
        {
            b.d[i]=s[i];
        }
        for(int i=b.len;i<a.len;i++)
        {
            b.d[i]=0;
            b.len++;
        }
        for(int i=0;i<b.len;i++)
        {
            s[i]=b.d[b.len-1-i];
        }
        for(int i=0;i<b.len;i++)
        {
            b.d[i]=s[i];
        }
    }
    int carry=0;
    /*for(int i=b.len-1;i>=0;i--)
    {
        printf("%d",b.d[i]);
    }
    printf("\n");*/
    for(int i=0;i<a.len||i<b.len;i++)
    {
        int temp=a.d[i]+b.d[i]+carry;
        carr.d[carr.len++]=temp%10;
        carry=temp/10;
    }
    /*for(int i=carr.len-1;i>=0;i--)
    {
        printf("%d",carr.d[i]);
    }
    printf("\n");
    printf("%d\n",carr.len);*/
    int t[maxn];
        for(int i=0;i<carr.len;i++)
        {
            t[i]=carr.d[carr.len-1-i];
        }
        for(int i=0;i<carr.len;i++)
        {
            carr.d[i]=t[i];
        }
    while(carr.d[carr.len-1]==0&&carr.len>=2)
    {
        carr.len--;
    }
    for(int i=0;i<carr.len;i++)
        {
            t[i]=carr.d[carr.len-1-i];
        }
        for(int i=0;i<carr.len;i++)
        {
            carr.d[i]=t[i];
        }
    return carry;
}
bign add2(bign a,bign b,int carry)
{
    bign c;
    for(int i=0;i<a.len||i<b.len;i++)
    {
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)
    {
        c.d[c.len++]=carry;
    }
    /*for(int i=c.len-1;i>=0;i--)
        {
            printf("%d",c.d[i]);
        }
        printf("\n");
        printf("%d\n",c.len);*/
        return c;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            char str1[maxn];
            char str2[maxn];
            bign a,b,c,e;
            scanf("%s",str1);
            chang(str1,a,b);
            scanf("%s",str2);
            chang(str2,c,e);
            /*for(int j=a.len-1;j>=0;j--)
            {
                printf("%d",a.d[j]);
            }
            printf("\n");*/
            bign carr,f;
            int carry;
            carry=add1(b,e,carr);
            f=add2(a,c,carry);
            for(int j=f.len-1;j>=0;j--)
            {
                printf("%d",f.d[j]);
            }
            printf(".");
            for(int j=carr.len-1;j>=0;j--)
            {
                printf("%d",carr.d[j]);
            }
            printf("\n");
            getchar();
        }
    }
    return 0;
}
