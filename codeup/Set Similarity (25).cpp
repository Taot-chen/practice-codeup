#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    set<int> a[55];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            a[i].insert(x);
        }
    }
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        int c,d;
        scanf("%d %d",&c,&d);
        int cnum=0,tnum=0;
        for(set<int>::iterator it=a[c-1].begin();it!=a[c-1].end();it++)
        {
            if(a[d-1].count(*it))
            {
                cnum++;
            }
            else tnum++;
        }
        double res=cnum*1.0/(a[d-1].size()+tnum)*100;
        printf("%.1f%%\n",res);
    }
    return 0;
}
