#include<cstdio>
const int maxn=1010;
int father[maxn];
int findfather(int x)
{
    int a=x;
    while(x!=father[x])
    {
        x=father[x];
    }
    while(a!=father[a])
    {
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void uni(int a,int b)
{
    int A=findfather(a);
    int B=findfather(b);
    if(A!=B)
    {
        father[A]=B;
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}
int main()
{
    int n,k;
    int dot1,dot2;
    while(scanf("%d%d",&n,&k),n!=0)
    {
        init(n);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&dot1,&dot2);
            uni(dot1,dot2);
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(father[i]==i)
            {
                res++;
            }
        }
        if(res==1&&k==n-1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
