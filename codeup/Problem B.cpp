#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
const int maxm=10;
int main()
{
    int a[maxm][maxm];
    int m;
    int b=0,c=0;
    while(scanf("%d",&m)!=EOF)
    {
        int s[m]={0},t[m]={0};
    int result[2*m+2]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            s[i]+=a[i][j];
            t[j]+=a[i][j];
            if(i==j)
            {
                b+=a[i][i];
            }
            if(j==m-1-i)
            {
                c+=a[i][j];
            }
        }
    }
    int k=0;
    for(int i=0;i<m;i++)
    {
        result[k++]=s[i];
        result[k++]=t[i];
    }
    result[k++]=b;
    result[k++]=c;
    sort(result,result+k,cmp);
    for(int i=0;i<k;i++)
    {
        printf("%d",result[i]);
        if(i!=k)
        {
            printf(" ");
        }
    }
    printf("\n");
    }

    return 0;
}
