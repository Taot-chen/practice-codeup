#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=26*26*26*10+10;
vector<int> stu[maxn];

//��ѧ��������ת�����������֣�����ʶ��
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
    int m,n,no,num;//�ĸ������ֱ�Ϊѧ���������γ��������γ̱�ź͸ÿγ�ѡ������
    char name[5];
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&no,&num);
        for(int j=0;j<num;j++)
        {
            scanf("%s",name);
            int id=change(name);
            stu[id].push_back(no);//�ѿγ̱�Ŵ洢�����ѧ��id��Ӧ���������������
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
