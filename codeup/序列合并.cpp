#include<cstdio>
#include<iostream>
#include<queue>
//#include<ctime>
using namespace std;
//time_t begin_t  = clock();
int n;
const int maxn=100010;
int a[maxn],b[maxn];
int res[maxn];
priority_queue<int> q;
int main()
{
    //scanf("%d",&n);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            q.push(a[1]+b[i]);
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]+b[j]<q.top())
                {
                    q.pop();
                    q.push(a[i]+b[j]);
                }
                else
                {
                    continue;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            res[i]=q.top();
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            printf("%d",res[i]);
            if(i<n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    //time_t finish_t = clock();
    //cout<<"it cost " << (double )(finish_t - begin_t )/CLOCKS_PER_SEC <<" s"<<endl;
    return 0;
}
