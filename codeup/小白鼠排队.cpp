#include<cstdio>
#include<algorithm>
#include<cstring>
const int maxn=100;
using namespace std;
struct ifo
{
    int weight;
    char color[15];
} mouse[maxn];
bool cmp(ifo a,ifo b)
{
    return a.weight>b.weight;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %s",&mouse[i].weight,mouse[i].color);
        }
        sort(mouse,mouse+n,cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",mouse[i].color);
        }
    }
    return 0;
}
