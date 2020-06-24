#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=110;
const int INF=0x3fffffff;

double G[maxn][maxn];
double d[maxn];
bool flag[maxn];
int n;

double prim()
{
    fill(d,d+maxn,INF*1.0);
    d[0]=0;
    double ans=0.0;
    fill(flag,flag+maxn,false);
    for(int i=0;i<n;i++)
    {
        int u=-1;
        double MIN=INF*1.0;
        for(int j=0;j<n;j++)
        {
            if(flag[j]==false&&MIN>d[j])
            {
                MIN=d[j];
                u=j;
            }
        }
        //printf("%d\n",u);
        if(u==-1)
        {
            return -1;
        }
        flag[u]=true;
        ans+=d[u];
        for(int v=0;v<n;v++)
        {
            if(flag[v]==false&&d[v]>G[u][v]);
            {
                d[v]=G[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    double x[maxn],y[maxn],w;
    //int u,v;
    while(scanf("%d",&n),n!=0)
    {
        fill(G[0],G[0]+maxn*maxn,INF*1.0);
        //scanf("%lf %lf",&x1,&y1);
        //G[0][0]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                G[i][j]=w;
                //printf("%f\n",w);
            }
        }
        double res=prim();
        printf("%.2f\n",res);
    }
    return 0;
}
