#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
struct food
{
    double j;
    double f;
    double h;
} fod[maxn];
bool cmp(food a,food b)
{
    return a.h<b.h;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n),m!=-1&&n!=-1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&fod[i].j,&fod[i].f);
            fod[i].h=fod[i].f/fod[i].j;//�����������ÿһ������ϲ������ʳ��Ҫ��è���ɱ�
        }
        sort(fod,fod+n,cmp);//���ռ۸�ӵ͵�������
        double sum=0;
        for(int i=0;i<n;i++)
        {
            if(m>=fod[i].f)
            {
                sum+=fod[i].j;
                m-=fod[i].f;
            }
            else
            {
                sum+=fod[i].j*(m/fod[i].f);
                m=0;
                break;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
