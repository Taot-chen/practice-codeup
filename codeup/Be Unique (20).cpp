#include<cstdio>
#include<cstring>
const int maxn=100010;
int a[maxn];
int hashtable[10010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(hashtable,0,sizeof(hashtable));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            hashtable[a[i]]++;
        }
        int maxa=0;
        for(int i=0;i<n;i++)
        {
            if(maxa<a[i])
            {
                maxa=a[i];
            }
        }
        //printf("%d\n",maxa);
        int j=0,p=0;
        for(int j=0;j<n;j++)
        {
            //printf("%d\n",j);
            if(hashtable[a[j]]==1)
            {
                printf("%d\n",a[j]);
                break;
            }
            p++;
        }
        //printf("%d\n",j);
        if(p==n) printf("None\n");
    }
    return 0;
}
