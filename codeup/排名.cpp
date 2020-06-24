#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ifo
{
    char id[25];
    int coun;
    int num[10];
    int score=0;
} stu[1000];
bool cmp(ifo a,ifo b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return a.id<b.id;
}
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int m,g,p=0;
        scanf("%d%d",&m,&g);
        int a[m];
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }

        //输入考生信息&计算每位考生的得分
        for(int i=0;i<n;i++)
        {
            scanf("%s %d",stu[i].id,&stu[i].coun);
            for(int j=0;j<stu[i].coun;j++)
            {
                scanf("%d",&stu[i].num[j]);
                stu[i].score+=a[stu[i].num[j]-1];
            }
        }
        /*for(int i=0;i<n;i++)
        {
            printf("%d ",stu[i].score);
        }
        printf("\n");*/
        //计算及格人数并排名
        for(int i=0;i<n;i++)
        {
            if(stu[i].score>=g) p++;
        }
        printf("%d\n",p);
        sort(stu,stu+n,cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s %d\n",stu[i].id,stu[i].score);
        }
    }
    return 0;
}
