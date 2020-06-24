#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {

        int a[N];
        int sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<N;i++)
        {
            sum+=a[i];
        }
        printf("%d\n",sum);
    }

    return 0;
}
