#include <cstdio>
#include <map>
#include <queue>

using namespace std;
char goal[10];
int start,termination;
struct node
{
	int step,cost,num,pos;
	node(int n,int s,int p)
	{
		num=n;
		step=s;
		pos=p;
		compute();
	}
	bool operator<(const node &no)const
	{
		return cost>no.cost;
	}
	void compute()
	{
		int c=0;
		char temp[10];
		sprintf(temp,"%09d",num);
		for(int i=0;i<9;i++)
		{
			if(temp[i]!=goal[i])
				c++;
		}
		cost=step+c;
	}
};
int director[9][4]={{-1,-1,3,1},{-1,0,4,2},{-1,1,5,-1},
{0,-1,6,4},{1,3,7,5},{2,4,8,-1},
{3,-1,-1,7},{4,6,-1,8},{5,7,-1,-1}};
void swap(char str[],int a,int b)
{
	char temp=str[a];
	str[a]=str[b];
	str[b]=temp;
}
bool judge(char a[],char b[])
{
	int r1=0,r2=0;
	for(int i=0;i<9;i++)
	{
		if(a[i]=='0')
			continue;
		for(int j=0;j<i;j++)
		{
			if(a[j]=='0')
				continue;
			if(a[j]>a[i])
				r1++;
		}
	}
	for(int i=0;i<9;i++)
	{
		if(b[i]=='0')
			continue;
		for(int j=0;j<i;j++)
		{
			if(b[j]=='0')
				continue;
			if(b[j]>b[i])
				r2++;
		}
	}
	if(r1%2==r2%2)
		return true;
	else
		return false;
}
priority_queue<node> p;
map<int,bool> mp;
int combine(int num,int pos)
{
	char temp[10];
	int temp1;
	node s(num,0,pos);
	p.push(s);
	mp[num]=true;
	while(!p.empty())
	{
		s=p.top();
		p.pop();
		sprintf(temp,"%09d",s.num);
		for(int i=0;i<4;i++)
		{
			if(director[s.pos][i]!=-1)
			{
				swap(temp,s.pos,director[s.pos][i]);
				sscanf(temp,"%d",&temp1);
				if(s.num==termination)
					return s.step+1;
				if(mp.count(temp1)==0)
				{
					node r(temp1,s.step+1,director[s.pos][i]);
					p.push(r);
					mp[temp1]=true;
				}
				swap(temp,s.pos,director[s.pos][i]);
			}
		}
	}
}

int main()
{
	int n,pos;
	char temp[10];
	while(~scanf("%d",&n))
	{

		start=n;
		for(int i=0;i<8;i++)
		{
			scanf("%d",&n);
			start=start*10+n;
		}
		sprintf(temp,"%09d",start);
		for(int i=0;i<9;i++)
			if(temp[i]=='0')
				pos=i;
		termination=0;
		for(int i=0;i<9;i++)
		{
			scanf("%d",&n);
			termination=termination*10+n;
		}
		sprintf(goal,"%09d",termination);
		if(judge(temp,goal))
		{
			int count=0;
			count=combine(start,pos);
			printf("%d\n",count);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
