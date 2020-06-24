#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=26*26*26*10+10;
vector<int> stu[maxn];

//将学生的名字转换成整形数字，方便识别
int change(char str[])
{
    int id=0;
    for(int i=0;i<3;i++)
    {
        id=id*26+(str[i]-'A');
    }
    id=id*10+(str[3]-'0');
    return id;
}
int main()
{
    int m,n,no,num;//四个变量分别为学生总数，课程总数，课程编号和该课程选课人数
    char name[5];
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&no,&num);
        for(int j=0;j<num;j++)
        {
            scanf("%s",name);
            int id=change(name);
            stu[id].push_back(no);//把课程编号存储到这个学生id对应的向量数组最后面
        }
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",name);
        int id=change(name);
        printf("%s",name);
        if(stu[id].size()==0)
        {
            printf(" %d\n",0);
        }
        else
        {
            printf(" %d",stu[id].size());
            sort(stu[id].begin(),stu[id].end());
            for(int j=0;j<stu[id].size();j++)
            {
                printf(" %d",stu[id][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
