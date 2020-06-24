#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=110;
const int maxm=510;
const int INF=-1;
int d[maxn][maxn],father[maxn];
int n;
int binarypow(int n,int m,int b)
{
    if(m==0)
    {
        return 1;
    }
    if(m%2==1)
    {
        return n*binarypow(n,m-1,b)%b;
    }
    else
    {
        int a=binarypow(n,m-1,b);
        return a*a%b;
    }
}
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        d[i][i]=0;
        father[i]=i;
    }
}
int findfather(int x)
{
    while(x!=father[x])
    {
        x=father[x];
    }
    return x;
}
int main()
{
    int m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        fill(d[0],d[0]+maxn*maxn,INF);
        init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            int x=findfather(u);
            int y=findfather(v);
            if(x!=y)
            {
                int dis=binarypow(2,i,100000);
                for(int j=0;j<n;j++)
                {
                    if(x==findfather(j))
                    {
                        for(int k=0;k<n;k++)
                        {
                            if(y==findfather(k))
                            {
                                d[j][k]=d[k][j]=(dis+d[j][u]+d[k][v])%100000;
                            }
                        }
                    }
                }
            }
            father[y]=x;
        }
        for(int i=1;i<n;i++)
        {
            printf("%d\n",d[0][i]);
        }
    }
    return 0;
}
