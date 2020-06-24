#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int dpl[maxn];
int dpr[maxn];
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        fill(dpl,dpl+maxn,0);
        fill(dpr,dpr+maxn,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    dpl[i]=max(dpl[i],dpl[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(a[i]>a[j])
                {
                    dpr[i]=max(dpr[i],dpr[j]+1);
                }
            }
            dpl[i]+=dpr[i]+1;
        }
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(res<dpl[i])
            {
                res=dpl[i];
            }
        }
        printf("%d\n",n-res);
    }
    return 0;
}
