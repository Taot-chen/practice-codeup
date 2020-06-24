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
    /*printf("%d\n",pnum);
    for(int i=0;i<pnum;i++)
    {
        printf("%d ",prime[i]);
    }
    printf("\n");*/
}
int isprime(int n)
{
    if(n<=1) return 0;
    int sqr=(int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0)
        {
            return 0;
            break;
        }
    }
    return 1;

}
int main()
{
    findprime();
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int m,cnt=0;
        for(int i=0;i<pnum;i++)
        {
            if(prime[i]>n/2) break;
            m=n-prime[i];
            //printf("%d\n",m);
            if(isprime(m)) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
