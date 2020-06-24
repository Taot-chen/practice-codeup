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
    int n,m;
    int node1,node2;
    while(scanf("%d",&n),n!=0)
    {
        scanf("%d",&m);
        init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&node1,&node2);
            uni(node1,node2);
        }
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(father[i]==i)
            {
                num++;
            }
        }
        printf("%d\n",num-1);
    }
    return 0;
}
