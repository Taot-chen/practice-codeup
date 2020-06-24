#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int M;
        int T=1;
        scanf("%d",&M);
        int sum=0;
        int a[M];
        for(int i=0;i<M;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<M;i++)
        {
            sum+=a[i];
        }
        printf("%d\n",sum);
        while(T--)
        {
            printf("\n");
        }
    }
    return 0;
}
