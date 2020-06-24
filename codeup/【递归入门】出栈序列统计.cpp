#include<cstdio>
#include<iostream>
using namespace std;
int n,cnt;
void f(int num,int po,int pu)//num表示栈中剩余的元素数量，po表示剩余pop操作的数量，pu表示剩余push操作的数量
{
    if(!po&&!pu)
    {
        cnt++;
    }
    if(po&&num)//可以执行pop操作的条件
    {
        f(num-1,po-1,pu);//执行一次pop之后的结果，进入下一层
    }
    if(pu)
    {
        f(num+1,po,pu-1);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        f(0,n,n);//在刚开始，栈内是空的，pop和push都可以操作n次
        cout<<cnt<<endl;
    }
    return 0;
}
