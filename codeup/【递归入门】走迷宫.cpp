#include<cstdio>
#include<iostream>
using namespace std;
int m,n;
bool flag=true;
int endx,endy;
int a[100][100];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
struct road
{
    int x,y;
} route[10000];
void f(int x,int y,int num)
{
    if(x==endx&&y==endy)
    {
        for(int i=0;i<num;i++)
        {
            printf("(%d,%d)->",route[i].x,route[i].y);
        }
        printf("(%d,%d)\n",endx,endy);
        flag=false;
    }
    route[num].x=x;
    route[num].y=y;
    for(int i=0;i<4;i++)
    {
        if(a[x+dx[i]][y+dy[i]]==1&&1<=x+dx[i]<=m&&1<=y+dy[i]<=n)
        {
            a[x][y]=0;//防止走回头路
            f(x+dx[i],y+dy[i],num+1);
            a[x][y]=1;//这条路走完之后再恢复这个节点的值
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int startx,starty;
        scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
        f(startx,starty,0);
        if(flag)
        {
            printf("-1\n");
        }
    }
    return 0;
}
