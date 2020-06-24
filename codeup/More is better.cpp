#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=10000010;
int father[maxn];
int isroot[maxn]={0};
set<int> a;
int findfather(int x)
{
    int a=x;
    while(a!=father[a])
    {
        a=father[a];
    }
    while(x!=father[x])
    {
        int z=x;
        x=father[x];
        father[z]=a;
    }
    return a;
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
    init(maxn);
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
        {
            printf("1\n");
            continue;
        }
        int node1,node2;
        int num=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&node1,&node2);
            uni(node1,node2);
            a.insert(node1);
            a.insert(node2);
        }
        int ans=0;
        for(set<int>::iterator it=a.begin();it!=a.end();it++)
        {
            isroot[findfather(*it)]++;
        }
        for(set<int>::iterator it=a.begin();it!=a.end();it++)
        {
           ans=max(ans,isroot[*it]);
        }
        printf("%d\n",ans);
        a.clear();
    }
    return 0;
}
