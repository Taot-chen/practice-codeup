#include<stdio.h>
int main()
{
    int a[10],b,i,j;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
       // int flag=1;
        for(j=0;j<10-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                b=a[j+1];
                a[j+1]=a[j];
                a[j]=b;
                //flag=0;
            }
        //n++;
        }
        //if(flag)
               // {
               //     break;
               // }
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
    //printf("½»»»%d´Î",n);
    return 0;
}
