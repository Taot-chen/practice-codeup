#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[n],b[n];
		for(int i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
		if(n>1)
		{
			//�ҳ�����Ԫ�� 
			int m=0,j=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]>m)
				{
					m=a[i];
					j=i;//a[j]������ 
				}
			}
		
			//��ȥ�����ֵ�������ŵ�b��
			int k=0;
			for(int i=0;i<n;i++)
			{
				if(i!=j)
				{
					b[k++]=a[i];
				}
			}
		
			//������b��������
			sort(b,b+n-1);
			printf("%d\n",m);
			for(int i=0;i<n-1;i++)
			{
				printf("%d ",b[i]);
			} 
			printf("\n");
		}
		else
		{
			printf("%d\n%d\n",a[0],-1);
		}
	}
	return 0;
} 
