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
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m;
        int node1,node2;
        scanf("%d%d",&n,&m);
        init(n);
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&node1,&node2);
            uni(node1,node2);
        }
        int res=0;
        for(int j=1;j<=n;j++)
        {
            if(father[j]==j)
            {
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
