#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=210;
int a[maxn];
int binarysearch(int a[],int left,int right,int x)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]>x)
        {
            right=mid-1;
        }
        else if(a[mid]<x)
        {
            left=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        printf("%d\n",binarysearch(a,0,n-1,x));
    }
    return 0;
}
