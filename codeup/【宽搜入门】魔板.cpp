#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;
char goal[10];
int termination;
struct node
{
	int step,num;
	vector<char> answer;
	node(int n,int s,vector<char> a)
	{
		num=n;
		step=s;
		answer=a;
	}
};
void swap(char str[],int flag,bool operate)
{
	if(flag==0)
	{
		char temp[8];
		for(int i=0;i<8;++i)
		{
			temp[i]=str[7-i];
		}
		for(int i=0;i<8;i++)
		{
			str[i]=temp[i];
		}
	}
	if(flag==1)
	{
		if(operate==true)
		{
			char temp=str[3];
			str[3]=str[2];
			str[2]=str[1];
			str[1]=str[0];
			str[0]=temp;
			temp=str[4];
			str[4]=str[5];
			str[5]=str[6];
			str[6]=str[7];
			str[7]=temp;
		}
		else
		{
			char temp=str[0];
			str[0]=str[1];
			str[1]=str[2];
			str[2]=str[3];
			str[3]=temp;
			temp=str[7];
			str[7]=str[6];
			str[6]=str[5];
			str[5]=str[4];
			str[4]=temp;
		}
	}
	if(flag==2)
	{
		if(operate==true)
		{
			char temp=str[1];
			str[1]=str[6];
			str[6]=str[5];
			str[5]=str[2];
			str[2]=temp;
		}
		else
		{
			char temp=str[1];
			str[1]=str[2];
			str[2]=str[5];
			str[5]=str[6];
			str[6]=temp;
		}
	}
}
queue<node> p;
map<int,bool> mp;
int combine(int num)
{
	char temp[10];
	int temp1;
	vector<char> answer;
	node s(num,0,answer);
	p.push(s);
	mp[num]=true;
	while(!p.empty())
	{
		s=p.front();
		p.pop();
		sprintf(temp,"%d",s.num);
		if(s.num==termination)
		{
			printf("%d\n",s.step);
			for(int i=0;i<s.step;++i)
			{
				if(i%60==0&&i!=0)
				{
					printf("%c\n",s.answer[i]);
				}
				else
				{
					printf("%c",s.answer[i]);
				}
			}
			return 0;
		}
		for(int i=0;i<3;i++)
		{
			swap(temp,i,true);
			sscanf(temp,"%d",&temp1);
			if(mp.count(temp1)==0)
			{
				node r(temp1,s.step+1,s.answer);
				r.answer.push_back(i+'A');
				p.push(r);
				mp[temp1]=true;
			}
			swap(temp,i,false);
		}
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		termination=n;
		for(int i=0;i<7;i++)
		{
			scanf("%d",&n);
			termination=termination*10+n;
		}
		combine(12345678);
	}
	return 0;
}
