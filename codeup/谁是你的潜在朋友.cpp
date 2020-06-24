#include<cstdio>
const int maxn=500;

int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int like[500]={0};
        int Hashtable[maxn]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%d",&like[i]);
            Hashtable[like[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(Hashtable[like[i]]==1)
            {
                printf("BeiJu\n");
            }
            else
            {
                printf("%d\n",Hashtable[like[i]]-1);
            }
        }
    }

    return 0;
}
