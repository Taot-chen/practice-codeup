#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1010;
int height=0;
struct node
{
    int layer;
    vector<int>child;
}tree[maxn];
void bfs(int root)
{
    queue<int>q;
    tree[root].layer=1;
    q.push(root);
    if(tree[root].layer>height)
    {
        height=tree[root].layer;
    }
    while(!q.empty())
    {
        int fron=q.front();
        q.pop();
        for(int i=0;i<tree[fron].child.size();i++)
        {
            int child=tree[fron].child[i];
            tree[child].layer=tree[fron].layer+1;
            q.push(child);
            if(tree[child].layer>height)
            {
                height+=1;
            }
            //q.pop();
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a,b;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            tree[a].child.push_back(b);
        }
        bfs(1);
        printf("%d\n",height);
    }
    return 0;
}
