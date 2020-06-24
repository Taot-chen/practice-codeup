#include<stdio.h>
int main()
{
    int a,b,c,d;

    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int str1[15],str2[15];
        int result=0;
        //数出a和b各有几位数
        int m=0,n=0;
        c=a;
        d=b;
        while(c)
        {
            //printf("%d\n",c%10);
            c=c/10;
            m++;
        }
        while(d)
        {
            //printf("%d\n",d%10);
            d=d/10;
            n++;
        }
        //printf("%d %d %d %d\n",a,b,m,n);
        for(int i=m-1;i>=0;i--)
        {
            str1[i]=a%10;
            a=a/10;
        }
        for(int i=n-1;i>=0;i--)
        {
            str2[i]=b%10;
            b=b/10;
        }
        /*for(int i=0;i<m;i++)
        {
            printf("%d\n",str1[i]);
        }*/
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result+=str1[i]*str2[j];
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
