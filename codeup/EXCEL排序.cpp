#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000;
struct stu
{
	int num;
	char name[10];
	int cj;
} a[maxn];
bool cmp1(stu a,stu b)
{
	return a.num<b.num;
}
bool cmp2(stu a,stu b)
{
	if(strcmp(a.name,b.name)!=0)
	return strcmp(a.name,b.name)<0;
	else return a.num<b.num;
}
bool cmp3(stu a,stu b)
{
	if(a.cj!=b.cj)
	return a.cj<=b.cj;
	else return a.num<b.num;
}
int main()
{
	int n;
	int order=1; 
	while(scanf("%d",&n),n!=0)
	{
		int b;
		scanf("%d",&b);
		for(int i=0;i<n;i++)
		{
			scanf("%d %s %d",&a[i].num,a[i].name,&a[i].cj);
		}
		printf("Case %d:\n",order);
		if(b==1)
		{
			sort(a,a+n,cmp1);
		}
		else if(b==2)
		{
			sort(a,a+n,cmp2);
		}
		else
		{
			sort(a,a+n,cmp3);
		}
		for(int i=0;i<n;i++)
		{
			printf("%06d %s %02d\n",a[i].num,a[i].name,a[i].cj);
		}
		order++;
	}
	return 0;
}
