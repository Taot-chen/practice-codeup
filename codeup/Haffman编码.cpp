#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=110;
struct HuffNode
{
	int w,parent,lchild,rchild;
	char s;
}Node[maxn*2];
void SearchMin(int &a,int &b,int n)
{
	int min=INT_MAX;
	for(int i=1;i<=n;++i)
	{
		if(Node[i].parent==0&&Node[i].w<min)
		{
			min=Node[i].w;
			a=i;
		}
	}
	min=INT_MAX;
	for(int i=1;i<=n;++i)
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
	if(Node[a].w==Node[b].w&&Node[a].s>Node[b].s)
	{
		swap(a,b);
	}
}
void HuffmanCode(int n,char * s,int * w,char * * &ans)
{
	int m=2*n-1;
	for(int i=1;i<=n;++i)
	{
		Node[i].parent=Node[i].lchild=Node[i].rchild=0;
		Node[i].w=w[i];
		Node[i].s=s[i];
	}
	for(int i=n+1;i<=m;++i)
	{
		int a,b;
		SearchMin(a,b,i-1);
		Node[i].lchild=a;
		Node[i].rchild=b;
		Node[i].w=Node[a].w+Node[b].w;
		Node[i].parent=0;
		Node[i].s=Node[a].s;
		Node[a].parent=Node[b].parent=i;
	}
	int c,f,index=0;
	char temp[n];
	ans=new char * [n+1];
	for(int i=1;i<=m;++i)
		Node[i].w=0;
	while(m)
	{
		if(Node[m].w==0)
		{
			Node[m].w=1;
			if(Node[m].lchild!=0)
			{
				m=Node[m].lchild;
				temp[index++]='0';
			}
			else if(Node[m].rchild==0)
			{
				ans[m]=new char[index+1];
				temp[index]='\0';
				strcpy(ans[m],temp);
			}
		}
		else if(Node[m].w==1)
		{
			Node[m].w=2;
			if(Node[m].rchild!=0)
			{
				m=Node[m].rchild;
				temp[index++]='1';
			}
		}
		else
		{
			Node[m].w=0;
			m=Node[m].parent;
			--index;
		}
	}
}
int main()
{
	int n,w[maxn];
	char s[maxn];
	char * * ans;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)
		{
			getchar();
			scanf("%c %d",&s[i],&w[i]);
		}
		HuffmanCode(n,s,w,ans);
		for(int i=1;i<=n;++i)
		{
			printf("%c:%s\n",s[i],ans[i]);
		}
	}
	delete ans;
    return 0;
}
