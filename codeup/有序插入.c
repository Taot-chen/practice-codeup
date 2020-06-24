#include<stdio.h>
int main()
{
    int a[10];
    int b, temp;
    for(int i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
    }
    a[9]=0;
    scanf("%d",&b);
    for(int i=0;i<9;i++)
    {
        if((a[i]<b)&&(a[i+1]>b))
        {
            for(int j=9;j>=i+2;j--)
            {
                a[j]=a[j-1];
            }
            a[i+1]=b;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
