#include<cstdio>
int main()
{
    int a[10];
    while(scanf("%d",&a[0])!=EOF)
    {
        for(int i=1;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        int temp,ma=0,mi=0;
        for(int i=1;i<10;i++)
        {
            if(a[ma]<a[i])
            {
                ma=i;
            }
            if(a[mi]>a[i])
            {
                mi=i;
            }
        }
        temp=a[ma];
        a[ma]=a[9];
        a[9]=temp;
        if(mi==9)
        {
            mi=ma;
        }
        temp=a[mi];
        a[mi]=a[0];
        a[0]=temp;
        for(int i=0;i<10;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
