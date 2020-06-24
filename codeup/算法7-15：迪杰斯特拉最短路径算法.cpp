#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3fffffff;//无穷大
const int maxn=55;//最大顶点数

int n;//n为顶点数
int G[maxn][maxn];//邻接矩阵
int d[maxn];//记录最短距离
bool flag[maxn]={false};

void dijkstra(int s)
{
    //flag[s]==true;
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(flag[j]==false&&d[j]<MIN)
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1)
        {
            return;
        }
        flag[u]=true;
        for(int v=0;v<n;v++)
        {
            if(flag[v]==false&&G[u][v]!=INF&&d[v]>d[u]+G[u][v])
            {
                d[v]=d[u]+G[u][v];
            }
        }
    }
}

int main()
{
    int s;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        int temp;
        fill(G[0],G[0]+maxn*maxn,INF);//初始化图G
        for(int i=0;i<n;i++)//输入邻接矩阵
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&temp);
                if(temp)
                {
                    G[i][j]=temp;
                }
            }
        }
        dijkstra(s);
        for(int i=0;i<n;i++)
        {
            if(i!=s)
            {
                if(d[i]==INF)
                {
                    printf("-1");
                }
                else
                {
                    printf("%d",d[i]);
                }
                if(i<n-1)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
