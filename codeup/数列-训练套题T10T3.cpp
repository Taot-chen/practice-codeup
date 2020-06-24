#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50010;
#define lowbit(i) ((i)&(-i))
int a[maxn],b[maxn];
int c[maxn];

void update(int x,int v)
{
    for(int i=x;i<maxn;i+=lowbit(i))
    {
        c[i]+=v;
    }
}

int getsum(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[n-1-i]=a[i];
        }
        int res=0;
        int p[n]={0},q[n]={0};
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            update(a[i],1);
            p[i]=getsum(a[i]-1);
        }
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            update(b[i],1);
            q[i]=getsum(b[i]-1);
        }
        for(int i=0;i<n;i++)
        {
            res+=p[i]*q[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
