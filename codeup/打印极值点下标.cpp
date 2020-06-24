#include<cstdio>
#include<algorithm>
using namespace std;
const int maxk=80;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            if(k==0) break;
            int a[maxk];
            int result[maxk];
            for(int j=0;j<k;j++)
            {
                scanf("%d",&a[j]);
            }
            int flag=0,t=0;
            if(a[0]!=a[1])
            {
                flag=1;
                result[t++]=0;
            }
            for(int j=1;j<k-1;j++)
            {
                if((a[j]>a[j-1]&&a[j]>a[j+1])||(a[j]<a[j-1]&&a[j]<a[j+1]))
                {
                    flag=1;
                    result[t++]=j;
                }
            }
            if(a[k-1]!=a[k-2])
            {
                flag=1;
                result[t++]=k-1;
            }
            if(flag==0) continue;
            for(int j=0;j<t;j++)
            {
                printf("%d",result[j]);
                if(j<t-1)
                {
                    printf(" ");
                }
                else printf("\n");
            }
        }
    }
    return 0;
}
