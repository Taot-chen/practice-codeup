#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=110;
int dp[maxn],M[maxn][maxn],r[maxn],n;
int subSeq()
{
	int ans=r[0];
	dp[0]=r[0];
	for(int i=1;i<n;++i)
	{
		dp[i]=max(r[i],dp[i-1]+r[i]);
		ans=max(ans,dp[i]);
	}
	return ans;
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&M[i][j]);
		int res=M[0][0];
		for(int i=0;i<n;++i)
		{
			fill(r,r+maxn,0);
			for(int j=i;j<n;++j)
			{
				for(int k=0;k<n;++k)
				{
					r[k]+=M[j][k];
				}
				res=max(res,subSeq());
			}
		}
		printf("%d\n",res);
	}
    return 0;
}
