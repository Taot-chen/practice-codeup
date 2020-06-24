#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

bool f[105][105][105];
struct node
{
	int jugs[3];
	int step;
	node(int s,int a,int b,int c)
	{
		step=s;
		jugs[0]=a;
		jugs[1]=b;
		jugs[2]=c;
	}
};
int combine(int a,int b,int c,int k)
{
	queue<node> p;
    node s(0,a,0,0);
    f[a][0][0]=true;
    p.push(s);
    int capacity[3];
    capacity[0]=a;
    capacity[1]=b;
    capacity[2]=c;
    int temp[3];
    int remain;
    while(!p.empty())
    {
    	s=p.front();
    	p.pop();
    	if(s.jugs[0]==k||s.jugs[1]==k||s.jugs[2]==k)
		{
			printf("yes\n%d\n",s.step);
			while(!p.empty())
				p.pop();
			return 1;
		}
    	for(int i=0;i<3;i++)
    	{
    		if(s.jugs[i]!=0)
    		{
    			for(int j=0;j<3;++j)
    			{
    				remain=capacity[j]-s.jugs[j];
    				if(j!=i&&remain!=0)
    				{
    					for(int x=0;x<3;++x)
    						temp[x]=s.jugs[x];
    					if(s.jugs[i]<remain)
    					{
    						temp[j]+=temp[i];
    						temp[i]=0;
						}
						else
						{
							temp[i]-=remain;
							temp[j]=capacity[j];
						}
						if(f[temp[0]][temp[1]][temp[2]]==false)
						{
							f[temp[0]][temp[1]][temp[2]]=true;
							node r(s.step+1,temp[0],temp[1],temp[2]);
    						p.push(r);
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int a,b,c,k,temp;
    while(~scanf("%d %d %d %d",&a,&b,&c,&k))
    {
    	if(a>b&&b>c&&c>=1&&a<=100&&k>=1&&k<=100&&k<=a)
    	{
    		memset(f,0,sizeof(f));
    		int flag=combine(a,b,c,k);
    		if(flag==0)
    			printf("no\n");
		}
		else
		{
			printf("no\n");
		}
    }
    return 0;
}
