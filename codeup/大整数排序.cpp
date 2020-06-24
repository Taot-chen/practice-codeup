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
    }
    return a;
}
bool cmp(bign a,bign b)
{
    if(a.len>b.len) return false;
    else if(a.len<b.len) return true;
    else
    {
        for(int i=a.len-1;i>=0;i--)
        {
            if(a.d[i]!=b.d[i])
            {
                return a.d[i]<b.d[i];
            }
        }
        return true;
    }
}
int main()
{
    int n;
    char str[maxn];
    while(scanf("%d",&n)!=EOF)
    {
        bign a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            a[i]=change(str);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=a[i].len-1;j>=0;j--)
            {
                printf("%d",a[i].d[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
