#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5010;
int p[maxn];
char a[maxn],b[maxn];
bool dp[maxn][maxn];
int main()
{
    while(gets(a))
    {
        int lena=0,lenb=0;
        while(a[lena]!='\0')
        {
            if(a[lena]>='a'&&a[lena]<='z')
            {
                b[lenb]=a[lena]-32;
                p[lenb]=lena;
                lenb++;
            }
            if(a[lena]>='A'&&a[lena]<='Z')
            {
                b[lenb]=a[lena];
                p[lenb]=lena;
                lenb++;
            }
            lena++;
        }
        int res=1;
        int maxr=1,start;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<lenb;i++)
        {
            dp[i][i]=1;
            if(i<lenb-1)
            {
                if(b[i]==b[i+1])
                {
                    res=2;
                    dp[i][i+1]=1;
                    if(res>maxr)
                    {
                        maxr=res;
                        start=i;
                    }
                }
            }
        }
        for(int L=3;L<lenb;L++)
        {
            for(int i=0;i+L-1<lenb;i++)
            {
                int j=i+L-1;
                if(b[i]==b[j]&&dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    res=L;
                    if(maxr<res)
                    {
                        maxr=res;
                        start=i;
                    }
                }
            }
        }
        for(int i=p[start];i<=p[start+res-1];i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
