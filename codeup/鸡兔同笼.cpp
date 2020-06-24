#include<cstdio>
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int n;
        scanf("%d",&n);
        if(n%2) printf("%d %d\n",0,0);
        else if(n%4==0) printf("%d %d\n",n/4,n/2);
        else printf("%d %d\n",n/4+1,n/2);
    }
    return 0;
}
