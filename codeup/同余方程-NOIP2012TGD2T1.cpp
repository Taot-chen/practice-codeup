#include<cstdio>
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-a/b*y;
    return g;
}
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
     int x,y;
     int g=exgcd(a,b,x,y);
     int res=(x%(b/g)+b/g)%(b/g);
     printf("%d\n",res);
    }
    return 0;
}
