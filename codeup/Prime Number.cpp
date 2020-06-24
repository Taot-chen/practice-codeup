#include<cstdio>
const int maxn=1000001;
int prime[maxn],pnum=0;
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
int main()
{
    findprime();
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        printf("%d\n",prime[k-1]);
    }
    return 0;
}
