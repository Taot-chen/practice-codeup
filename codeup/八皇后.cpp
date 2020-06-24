#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=105;
bool hashtable[maxn]={false};
int P[maxn];
char result[105][20]={0};
int cnt=0;
int n;
void generateP(int index)
{
    if(index==n+1)
    {
        cnt++;
        for(int i=1;i<=n;i++)
        {
            result[cnt][i-1]=P[i]+'0';
        }
        return;
    }
    for(int x=1;x<=n;x++)
    {
        if(hashtable[x]==false)
        {
            bool flag=true;
            for(int pr=1;pr<index;pr++)
            {
                if(abs(index-pr)==abs(x-P[pr]))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                P[index]=x;
                hashtable[x]=true;
                generateP(index+1);
                hashtable[x]=false;
            }
        }
    }
}
int main()
{
    int t;
    n=8;
    generateP(1);
    while(scanf("%d",&t)!=EOF)
    {
        for(int i=0;i<t;i++)
        {
            int b;
            scanf("%d",&b);
            printf("%s\n",result[b]);
        }
    }
    return 0;
}
