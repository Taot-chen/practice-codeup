#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int n,weight;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&weight);
            q.push(weight);
        }
        int res=0;
        while(q.size()>1)
        {
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            q.push(x+y);
            res+=x+y;
        }
        printf("%d\n",res);
    }
    return 0;
}
