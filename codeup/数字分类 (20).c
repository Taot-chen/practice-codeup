#include<stdio.h>
#include<stdio.h>
int main()
{
    int maxn=1000;
    int a[maxn];
    int N;
    scanf("%d",&N);
    //while(scanf("%d",&N)!=EOF)
    //{
        double A4=0;
        int A1=0,A2=0,A3=0,A5=0;
        double sum=0;
        int n=0;
        double flag=1.0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(a[i]%5==0&&a[i]%2==0)
            {
                A1+=a[i];
            }
            else if(a[i]%5==1)
            {
                A2+=flag*a[i];
                flag=-flag;
                //printf("%f\n",A[1]);
            }
            else if(a[i]%5==2)
            {
                A3++;
            }
            else if(a[i]%5==3)
            {
                sum+=a[i];
                n++;
            }
            else if(a[i]%5==4)
            {
                if(a[i]>A5)
                {
                    A5=a[i];
                }
            }
        }
        A4=((double) sum)/n;
        //printf("%f %f\n",sum,A[3]);
        if(A1!=0)
        {
            printf("%d ",A1);
        }
        else printf("N ");
        if(A2!=0)
        {
            printf("%d ",A2);
        }
        else printf("N ");
        if(A3!=0)
        {
            printf("%d ",A3);
        }
        else printf("N ");
        if(sum!=0)
        {
            printf("%.1f ",A4);
        }
        else printf("N ");

        if(A5!=0)
        {
            printf("%d\n",A5);
        }
        else printf("N\n");
    //}

    return 0;
}
