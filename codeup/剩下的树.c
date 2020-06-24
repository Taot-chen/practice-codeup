#include<stdio.h>
int main()
{
    int L,M;
    while(scanf("%d %d",&L,&M),L!=0,M!=0)
    {
        int count=0;
        int N=L+1;
        int a[N],b[M],c[M];
        for(int i=0;i<N;i++)
        {
            a[i]=i;   //初始化这条路
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&b[i],&c[i]);//用两个数组分别来存储区间的首尾
        }
        for(int i=0;i<M;i++)
        {
            for(int j=b[i];j<=c[i];j++)
            {
                a[j]=-1;//把拔掉的树都标记成-1
            }
        }
        for(int i=0;i<N;i++)
        {
            if(a[i]!=-1)
            {
                count++;//数出来未被拔掉的树的数量
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
