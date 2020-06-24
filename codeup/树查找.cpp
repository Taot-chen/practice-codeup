#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1010;
int a[maxn];
int index[15];
void compute()
{
    for(int i=0;i<15;i++)
    {
        index[i]=(int)pow(2.0,1.0*i);
    }
}
int main()
{
    compute();
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int d;
        scanf("%d",&d);
        int sum=0;
        int j=0;
        for(j=0;j<d-1;j++)
        {
            sum+=index[j];
        }
        if(sum>n)
        {
            printf("EMPTY\n");
        }
        else
        {
            int cnt=sum+index[j];
            if(cnt<=n)
            {
                for(int i=sum;i<cnt;i++)
                {
                    printf("%d",a[i]);
                    if(i<cnt-sum)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("\n");
                    }
                }
            }
            else
            {
                for(int i=sum;i<n;i++)
                {
                    printf("%d",a[i]);
                    if(i<n-sum)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("\n");
                    }
                }
            }
        }
    }
    return 0;
}
