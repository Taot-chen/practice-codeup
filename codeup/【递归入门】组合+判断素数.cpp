#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[25];
int sum,cnt;
int n,k;
bool judge(int a)//判断素数
{
    if(a<=1)
    {
        return false;
    }
    int b=(int)sqrt(1.0*a);
    for(int i=2;i<=b;i++)
    {
        if(a%i==0)
        {
            return false;
            break;
        }
    }
    return true;
}
void f(int r,int num)
{
    if(num==k)
    {
        if(judge(sum))
        {
            cnt++;
        }
    }
    for(int i=r;i<n;i++)
    {
        sum+=a[i];//选择了第i个元素
        f(i+1,num+1);//进入下一层
        sum-=a[i];//不选择第i个元素
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        //sort(a,a+n);
        sum=0;
        cnt=0;
        f(0,0);
        printf("%d\n",cnt);
    }
    return 0;
}
