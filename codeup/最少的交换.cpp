#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500010;
#define lowbit(i) ((i)&(-i))

struct node
{
    int value;
    int pos;
}temp[maxn];
int a[maxn],c[maxn];

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

bool cmp(node a,node b)
{
    return a.value<b.value;
}

int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp[i].value);
            temp[i].pos=i;
        }
        sort(temp,temp+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(i==0||temp[i].value!=temp[i-1].value)
            {
                a[temp[i].pos]=i+1;
            }
            else
            {
                a[temp[i].pos]=a[temp[i-1].pos];
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            update(a[i],1);
            //printf("%d\n",getsum(a[i]));
            //printf("%d\n",getsum(n)-getsum(a[i]));
            res+=getsum(n)-getsum(a[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
