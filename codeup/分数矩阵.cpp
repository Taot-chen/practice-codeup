#include<cstdio>
//const int maxn=50010;
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        double sum=n;//对角线元素之和
        //printf("%.2f\n",sum);
        for(int i=1;i<n;i++)//其余元素之和
        {
            sum+=2*(double)(n-i)/(1+i);
            //printf("%.2f\n",sum);
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
