#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=55;
const int INF=0x3fffffff;

int n;
int G[maxn][maxn];

void floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j])
                {
                    G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        //fill(G[0],G[0]+maxn*maxn,INF);
        //int temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&G[i][j]);
                if(G[i][j]==0&&i!=j)
                {
                    G[i][j]=INF;
                }
            }
        }
        floyd();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][j]!=INF)
                {
                    printf("%d ",G[i][j]);
                }
                else
                {
                    printf("-1 ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
