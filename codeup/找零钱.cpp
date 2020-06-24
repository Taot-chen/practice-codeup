#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[5]={0};
        int b[5]={50,20,10,5,1};
        while(n>0)
        {
            if(n>=50)
            {
                a[0]++;
                n-=50;
            }
            else if(n>=20)
            {
                a[1]++;
                n-=20;
            }
            else if(n>=10)
            {
                a[2]++;
                n-=10;
            }
            else if(n>=5)
            {
                a[3]++;
                n-=5;
            }
            else if(n>=1)
            {
                a[4]++;
                n-=1;
            }
        }
        int i=0;
        for(;i<5;i++)
        {
            if(a[i]>0)
            {
                printf("%d*%d",b[i],a[i]);
                break;
            }
        }
        for(int j=i+1;j<5;j++)
        {
            if(a[j]>0)
            {
                printf("+%d*%d",b[j],a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
