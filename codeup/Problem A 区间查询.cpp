#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=30010;
int a[maxn];
int main()
{
    int T,N,u,v,res;
    char cmd[20];
    while(scanf("%d",&T)!=EOF)
    {
        for(int i=1;i<=T;i++)
        {
            printf("Case %d:\n",i);
            scanf("%d",&N);
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&a[j]);
            }
            while(scanf("%s",cmd)!=EOF)
            {
                scanf("%d %d",&u,&v);
                if(strcmp(cmd,"Add")==0)
                {
                    a[u]+=v;
                }
                else if(strcmp(cmd,"Sub")==0)
                {
                    a[u]-=v;
                }
                else if(strcmp(cmd,"Query")==0)
                {
                    res=0;
                    for(int k=u;k<=v;k++)
                    {
                        res+=a[k];
                    }
                    printf("%d\n",res);
                }
                else if(strcmp(cmd,"End")==0)
                {
                    break;
                }
            }
        }
    }
    return 0;
}
