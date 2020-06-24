#include<cstdio>
#include<cmath>
const int maxn=100010;
int prime[maxn];
int pnum=0;
bool p[maxn]={0};
void findprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(p[i]==false)
        {
            prime[pnum++]=i;
            for(int j=i+i;j<maxn;j+=i)
            {
                p[j]=true;
            }
        }
    }
}
int fenjie(int n)
{
    int res=0;
    int sqr=(int)sqrt(1.0*n);
    for(int i=0;i<pnum&&prime[i]<=sqr;i++)
    {
        while(n%prime[i]==0)
        {
            res++;
            n/=prime[i];
        }
    }
    if(n==1) return res;
    else return res+1;
}
int main()
{
    findprime();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=fenjie(n);
        printf("%d\n",cnt);
    }
    return 0;
}
