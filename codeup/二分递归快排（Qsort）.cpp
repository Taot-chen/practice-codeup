#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int randpart(int a[],int left,int right)
{
    int p=(round(1.0*rand()/RAND_MAX)*(right-left)+left);
    swap(a[p],a[left]);
    int temp=a[left];
    while(left<right)
    {
        while(left<right&&a[right]>temp)
        {
            right--;
        }
        a[left]=a[right];
        while(left<right&&a[left]<temp)
        {
            left++;
        }
        a[right]=a[left];
    }
    a[left]=temp;
    return left;
}
void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int pos=randpart(a,left,right);
        quicksort(a,left,pos-1);
        quicksort(a,pos+1,right);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
