#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    long long A,B;
    while(scanf("%lld %d %lld %d",&A,&a,&B,&b)!=EOF)
    {
        int m=0,n=0;
        long long e=A,f=B;
        while(e)
        {
            e=e/10;
            m++;
        }
        while(f)
        {
            f=f/10;
            n++;
        }
        int c[15],d[15];
        for(int i=m-1;i>=0;i--)
        {
            c[i]=A%10;
            A=A/10;
        }
        for(int i=n-1;i>=0;i--)
        {
            d[i]=B%10;
            B=B/10;
        }
        long long pa=0,pb=0;
        double r1=0,r2=0;
        for(int i=0;i<m;i++)
        {
            if(c[i]==a)
            {
                pa+=a*(pow(10.0,r1));
                r1++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(d[i]==b)
            {
                pb+=b*(pow(10.0,r2));
                r2++;
                //printf("%lld\n",pb);
            }
        }
        //printf("%lld %lld\n",pa,pb);
        printf("%lld\n",pa+pb);
    }
    return 0;
}
