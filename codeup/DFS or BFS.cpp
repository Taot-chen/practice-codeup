#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
char a[8][9];
bool flag;
int dx[] = {0, 1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
struct node
{
    int x,y;//存放坐标
    int step;//存放步数
} temp,mi;//temp是当前点
bool test(int x,int y)
{
    if(x>7||x<0||y>7||y<0)
    {
        return false;
    }
    return true;
}
void bfs()
{
    queue<node> q;
    temp.x=7;//起始点参数
    temp.y=0;
    temp.step=0;
    q.push(temp);//起始点入队
    while(!q.empty())
    {
        temp=q.front();//访问队首元素
        q.pop();//队首元素出队
        for(int i=0;i<9;i++)
        {
            mi.x=temp.x+dx[i];
            mi.y=temp.y+dy[i];
            mi.step=temp.step+1;
            if(test(mi.x,mi.y)&& a[mi.x-mi.step+1][mi.y] != 'S' && a[mi.x-mi.step][mi.y] != 'S')
                //判断下一个点是否在界内，以及所走下一个点和所走点的上面否有石头
                //其中if中的第二个条件是所走点的下一步，第三个条件是所走点的上面
                //由于上面一行所说的所走点就是接下来要走的点，因此需要判断所走点的上面和所走点的下一步
                //如果满足上面的条件，就把所走的点入队
                //由于此处没有禁止走回头路，所以必须要提前判断是否一定能够到达终点
            {
                if(mi.step>8||a[mi.x][mi.y]=='A')
                {
                    flag=1;
                }
                q.push(mi);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int k=1;
    getchar();//吸收t后面的换行符（因为下面要用到%s来输入字符串，避免把这个换行符输入了）
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<8;j++)
        {
            scanf("%s",a[j]);
        }//输入完毕
        flag=0;
        bfs();
        printf("Case #%d: ",k);
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        k++;
    }
    return 0;
}
