#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
const int maxm=110;
int a[maxn],b[maxn];
int binarysearch(int a[],int left,int right,int x)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==x)
        {
            return 1;
        }
        else if(a[mid]>x)
        {
            right=mid-1;
        }
        else if(a[mid]<x)
        {
            left=mid+1;
        }
    }
    return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            if(binarysearch(a,0,n-1,b[i]))
            {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}
