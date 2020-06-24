#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int bn=0,pr=1;
        while(n)
        {
            bn+=(n%8)*pr;
            n/=8;
            pr*=10;
        }

        printf("%d\n",bn);
    }
    return 0;
}
