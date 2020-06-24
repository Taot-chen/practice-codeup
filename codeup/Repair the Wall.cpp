#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=600;
int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int l,n;
    while(scanf("%d%d",&l,&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        int sum=0,k=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            k++;
            if(sum>=l)
            {
                break;
            }
        }
        if(k<=n&&sum>=l)
        {
            printf("%d\n",k);
        }
        else printf("impossible\n");
    }
    return 0;
}
