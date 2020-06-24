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
    int x,y;//�������
    int step;//��Ų���
} temp,mi;//temp�ǵ�ǰ��
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
    temp.x=7;//��ʼ�����
    temp.y=0;
    temp.step=0;
    q.push(temp);//��ʼ�����
    while(!q.empty())
    {
        temp=q.front();//���ʶ���Ԫ��
        q.pop();//����Ԫ�س���
        for(int i=0;i<9;i++)
        {
            mi.x=temp.x+dx[i];
            mi.y=temp.y+dy[i];
            mi.step=temp.step+1;
            if(test(mi.x,mi.y)&& a[mi.x-mi.step+1][mi.y] != 'S' && a[mi.x-mi.step][mi.y] != 'S')
                //�ж���һ�����Ƿ��ڽ��ڣ��Լ�������һ��������ߵ���������ʯͷ
                //����if�еĵڶ������������ߵ����һ�������������������ߵ������
                //��������һ����˵�����ߵ���ǽ�����Ҫ�ߵĵ㣬�����Ҫ�ж����ߵ����������ߵ����һ��
                //�������������������Ͱ����ߵĵ����
                //���ڴ˴�û�н�ֹ�߻�ͷ·�����Ա���Ҫ��ǰ�ж��Ƿ�һ���ܹ������յ�
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
    getchar();//����t����Ļ��з�����Ϊ����Ҫ�õ�%s�������ַ����������������з������ˣ�
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<8;j++)
        {
            scanf("%s",a[j]);
        }//�������
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
