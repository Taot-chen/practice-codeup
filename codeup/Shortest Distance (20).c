#include<stdio.h>
int main()
{
    int N,M;
    scanf("%d",&N);
    int a[N];
    int total=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    /*for(int i=0;i<N;i++)
    {
        total+=a[i];
    }*/
    //printf("%d",total);
    scanf("%d",&M);
    int b[M][2];
    int c[M];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    /*for(int i=0;i<M;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",b[i][j]);
        }
            printf("\n");
    }*/
    for(int i=0;i<M;i++)
    {
        int d=0,e=0;
        if(b[i][0]>b[i][1])
        {
            int temp=b[i][0];
            b[i][0]=b[i][1];
            b[i][1]=temp;
        }
        for(int j=b[i][0]-1;j<b[i][1]-1;j++)
        {
            e+=a[j];
        }
        d=total-e;
        //printf("%d %d\n",e,d);
        if(e>d)
        {
            printf("%d\n",d);
        }
        else printf("%d\n",e);
    }
    return 0;
}
