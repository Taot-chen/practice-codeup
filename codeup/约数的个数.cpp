#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        int a[n]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            int cnt=0;
            for(int j=1;j<=a[i];j++)
            {
                if(a[i]%j==0) cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
