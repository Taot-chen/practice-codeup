#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=5010;
int a[maxn];

int randpart(int a[],int left,int right)
{
    int p=(round(1.0*rand()/RAND_MAX)*(right-left)+left);//生成[left，right]之间的随机数
    swap(a[left],a[p]);//交换a[left]和a[p]
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
        int mid=randpart(a,left,right);
        quicksort(a,left,mid-1);
        quicksort(a,mid+1,right);
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
