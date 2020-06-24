#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int resmax,resmin;
        resmax=max(a[0],a[1]);
        resmin=min(a[0],a[1]);
        for(int i=2;i<n;i++)
        {
            resmax=max(resmax,a[i]);
            resmin=min(resmin,a[i]);
        }
        printf("%d %d\n",resmax,resmin);
    }
    return 0;
}
