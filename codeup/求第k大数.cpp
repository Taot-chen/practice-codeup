#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
const int maxn=1000010;
int a[maxn];

//随机选取主元，划分区间
int randpart(int a[],int left,int right)
{
    int p=round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(a[left],a[p]);
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

//随机选择，返回第K大的数
int randselect(int a[],int left,int right,int k)
{
    if(left==right)
    {
        return a[left];
    }
    int p=randpart(a,left,right);
    int m=p-left+1;
    if(k==m)
    {
        return a[p];
    }
    if(k<m)
    {
        return randselect(a,left,p-1,k);
    }
    else return randselect(a,p+1,right,k-m);
}
int main()
{
    srand((unsigned)time(NULL));
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int k;
        scanf("%d",&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int res=randselect(a,0,n-1,n-k+1);
        printf("%d\n",res);
    }
    return 0;
}
