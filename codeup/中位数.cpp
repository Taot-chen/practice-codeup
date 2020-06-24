#include<cstdio>
#include<algorithm>
using namespace std;
int panduan(int n)
{
    return n%2;
}
const int maxn=10000;
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        /*for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");*/
        if(panduan(n))
        {
            printf("%d\n",a[n/2]);
        }
        else
        {
            printf("%d\n",(a[n/2]+a[n/2-1])/2);
        }
    }
    return 0;
}
