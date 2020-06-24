#include<cstdio>
#include<iostream>
int gcd(int a,int b)
{
    if(!b)
    {
        return a;
    }
    else return gcd(b,a%b);
}
int main()
{
    int ca,cb,n;
    while(scanf("%d%d%d",&ca,&cb,&n)!=EOF)
    {
        int m=n;
        if(ca+cb<n||n%gcd(ca,cb))
        {
            printf("It's impossible!\n");
        }
        else
        {
            int va=ca,vb=cb;
            while(n)
            {
                vb=cb;
                printf("fill B\n");
                while(vb>va)
                {

                    vb-=va;
                    printf("pour B A\n");
                    if(vb>va)
                    {
                        printf("empty A\n");
                    }

                }
                if(n-2*gcd(ca,cb)>0)
                {
                    printf("empty A\n");
                    printf("pour B A\n");
                }
                if(n%2)
                {
                    n-=gcd(ca,cb);
                }
                else
                {
                    n-=2*gcd(ca,cb);
                }

            }
            if(m%2==0)
            {
                printf("empty A\n");
                printf("pour B A\n");
            }
            printf("success\n");
        }
    }
    return 0;
}
