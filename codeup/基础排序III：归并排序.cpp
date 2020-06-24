#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=100010;
int a[maxm];
const int maxn=100010;
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }
        mergesort(a,0,m-1);
        for(int j=0;j<m;j++)
        {
            printf("%d\n",a[j]);
        }
    }
    return 0;
}
