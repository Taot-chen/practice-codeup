#include<stdio.h>
int main()
{
    int m;
    while(scanf("%d",&m),m!=0)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        //printf("%d %lld %lld\n",m,a,b);
        long long sum=a+b;
        //printf("%lld\n",sum);
        int msum[100],num=0;
        do
        {
            msum[num++]=sum%m;
            sum/=m;
        }while(sum!=0);
        for(int i=num-1;i>=0;i--)
        {
            printf("%d",msum[i]);
        }
        printf("\n");
    }
    return 0;
}
