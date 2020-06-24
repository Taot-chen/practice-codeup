#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=110;
struct HuffNode
{
	int w,parent,lchild,rchild;
}Node[maxn*2];
void SearchMin(int &a,int &b,int n)
{
	int min=INT_MAX;
	for(int i=0;i<n;++i)
	{
		if(Node[i].parent==0&&Node[i].w<min)
		{
			min=Node[i].w;
			a=i;
		}
	}
	min=INT_MAX;
	for(int i=0;i<n;++i)
	{
		if(Node[i].parent==0&&Node[i].w<min&&i!=a)
		{
			min=Node[i].w;
			b=i;
		}
	}
	if(a>b)
	{
		swap(a,b);
	}
}
void HuffmanCode(int n,int * w,char * * &ans)
{
	for(int i=0;i<n;++i)
	{
		Node[i].parent=Node[i].lchild=Node[i].rchild=0;
		Node[i].w=w[i];
	}
	for(int i=n;i<2*n-1;++i)
	{
		int a,b;
		SearchMin(a,b,i);
		Node[i].lchild=a;
		Node[i].rchild=b;
		Node[i].w=Node[a].w+Node[b].w;
		Node[a].parent=Node[b].parent=i;
	}
	int c,f,index;
	char temp[n];
	ans=new char * [n];
	for(int i=0;i<n;++i)
	{
		c=i;
		index=n-1;
		temp[index]=0;
		while(Node[c].parent!=0)
		{
			f=Node[c].parent;
			if(Node[f].lchild==c)
				temp[--index]='0';
			else
				temp[--index]='1';
			c=f;
		}
		ans[i]=new char[n-index];
		strcpy(ans[i],temp+index);
	}
}
int main()
{
	int n,w[maxn];
	char * * ans;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&w[i]);
		}
		HuffmanCode(n,w,ans);
		for(int i=0;i<n;++i)
		{
			printf("%s\n",ans[i]);
		}
	}
	delete ans;
    return 0;
}
