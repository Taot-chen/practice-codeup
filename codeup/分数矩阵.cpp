#include<cstdio>
//const int maxn=50010;
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        double sum=n;//�Խ���Ԫ��֮��
        //printf("%.2f\n",sum);
        for(int i=1;i<n;i++)//����Ԫ��֮��
        {
            sum+=2*(double)(n-i)/(1+i);
            //printf("%.2f\n",sum);
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
