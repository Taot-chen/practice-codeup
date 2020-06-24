#include<cstdio>
#include<queue>
using namespace std;
int n,x,y,num;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            q.push(num);
        }
        while(q.size()>1)
        {
            x=q.top();
            q.pop();
            y=q.top();
            q.pop();
            q.push(x+y);
            res+=x+y;
        }
        printf("%d\n",res);
    }
    return 0;
}
