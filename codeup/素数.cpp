#include<cstdio>
const int maxn=10010;
int prime[maxn],pnum=0;
bool p[maxn]={0};
void findprime()
{
    for(int i=2;i<maxn;i++)
    {
        //printf("%d ",p[i]);
        if(p[i]==0)
        {
            prime[pnum++]=i;
            for(int j=i+i;j<maxn;j=j+i)
            {
                p[j]=1;
            }
        }
    }
}
int main()
{
    findprime();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int result[maxn]={0};
        int m=0;
        for(int i=2;prime[i]<n;i++)
        {
            //printf("%d ",prime[i]);
            if(prime[i]%10==1)
            {
                result[m++]=prime[i];
            }
        }
        if(m==0)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                printf("%d",result[i]);
                if(i<m-1)
                {
                    printf(" ");
                }
                else printf("\n");
            }
        }
    }
    return 0;
}
