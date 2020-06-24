#include<stdio.h>
int main()
{
    int i=1;
    while(i)
    {
        int sum=0;
        int N;
        scanf("%d",&N);
        int a[N];
        if(N)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&a[j]);
            }
            for(int j=0;j<N;j++)
            {
                sum+=a[j];
            }
            printf("%d\n",sum);
        }
        else break;
    }
    return 0;
}
