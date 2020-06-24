#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000;
int dp[maxn];
struct BG
{
	int h,l,t;
}bg[maxn];

bool cmp(const BG a,const BG b)
{
	return a.t<b.t;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n<0)
			break;
		int max1=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d",&bg[i].h,&bg[i].l,&bg[i].t);
			if(bg[i].t>max1)
				max1=bg[i].t;
		}
		sort(bg+1,bg+n+1,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			for(int j=bg[i].t;j>=bg[i].l;--j)
			{
				dp[j]=max(dp[j],dp[j-bg[i].l]+bg[i].h);
			}
		}
		int result=dp[max1];
		for(int j=max1;j>=1;--j)
			if(result<dp[j])
				result=dp[j];
		printf("%d\n",result);
	}
	return 0;
}
