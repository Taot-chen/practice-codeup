#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=2510;
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
void rechange(int x,char str[])
{
    str[4]='\0';
    str[3]=x%10+'0';
    x/=10;
    for(int i=2;i>=0;i--)
    {
        str[i]=x%26+'A';
        x/=26;
    }
}
int main()
{
    int m,n;
    char name[10];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        scanf("%s",name);
        int id=change(name);
        int num;
        scanf("%d",&num);
        int a;
        for(int j=0;j<num;j++)
        {
            scanf("%d",&a);
            stu[a].push_back(id);
        }
    }
    for(int i=1;i<n+1;i++)
    {
        sort(stu[i].begin(),stu[i].end());
        printf("%d %d\n",i,stu[i].size());
        for(int j=0;j<stu[i].size();j++)
        {
            rechange(stu[i][j],name);
            printf("%s\n",name);
        }
    }
    return 0;
}
