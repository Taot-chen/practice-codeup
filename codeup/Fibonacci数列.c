#include<stdio.h>
int main()
{
    int n,F=1,i,H=1,G=1;
    scanf("%d",&n);
    if(n>50)
        printf("输入数字不得超过50\n");
        else
        {
            if((n==1)||(n==2))
                printf("%d\n",F);
            else
                {
                    for(i=3;i<=n;i++)
                    {
                        F=G+H;
                        G=H;
                        H=F;
                    }
                    printf("%d\n",F);
                }
        }

    return 0;
}
