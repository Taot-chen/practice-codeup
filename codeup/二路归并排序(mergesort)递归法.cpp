#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
void mergr(int a[],int l1,int r1,int l2,int r2)
{
    int i=l1,j=l2;
    int tempt[maxn];
    int index=0;
    while(i<=r1&&j<=r2)
    {
        if(a[i]<=a[j])
        {
            tempt[index++]=a[i++];
        }
        else tempt[index++]=a[j++];
    }
    while(i<=r1)
    {
        tempt[index++]=a[i++];
    }
    while(j<=r2)
    {
        tempt[index++]=a[j++];
    }
    for(i=0;i<index;i++)
    {
        a[l1+i]=tempt[i];
    }
}

void mergesort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        mergr(a,left,mid,mid+1,right);
    }
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
        mergesort(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
