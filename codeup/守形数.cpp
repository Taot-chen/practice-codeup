#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a=0,b=0,i=0,c=1;
        a=n*n;
        while(a>0)
        {
            a/=10;
            i++;
        }
        //printf("%d\n",i);
        for(int j=1;j<i;j++)
        {
            c*=10;
        }
        b=(n*n)%c;
        //printf("%d\n",b);
        if(b==n)
        {
            printf("YES!\n");
        }
        else printf("NO!\n");
    }
    return 0;
}
