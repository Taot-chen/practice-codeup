#include<cstdio>
int C(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else return C(n-1)+C(n-2);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",C(n));
    }
    return 0;
}
