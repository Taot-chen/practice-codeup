#include<cstdio>
int main()
{
    int a,b,c;
    for(a=0;a<=9;a++)
    {
        for(b=0;b<=9;b++)
        {
            for(c=0;c<=9;c++)
            {
                int m=100*a+10*b+c;
                int n=100*b+10*c+c;
                if(m+n==532)
                {
                    printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
}
