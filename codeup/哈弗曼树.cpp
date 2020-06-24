#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1010;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{

    int n,temp;
    while(scanf("%d",&n)!=EOF)
    {
        while(!q.empty())
        {
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            q.push(temp);
        }
        if(q.size()==1)
        {
            printf("%d\n",q.top());
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
