#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
