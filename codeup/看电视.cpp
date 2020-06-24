#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct timelist
{
    int s;
    int e;
}show[maxn];
bool cmp(timelist a,timelist b)
{
    if(a.s!=b.s) return a.s>b.s;
    else return a.e<b.e;
}
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&show[i].s,&show[i].e);
        }
        sort(show,show+n,cmp);//把时间段的起始点按照从大到小的顺序排列；
        int result=1,lasts=show[0].s;
        for(int i=1;i<n;i++)
        {
            if(lasts>=show[i].e)
            {
                result++;
                lasts=show[i].s;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
