#include<stdio.h>
int main()
{
    int L,M;
    while(scanf("%d %d",&L,&M),L!=0,M!=0)
    {
        int count=0;
        int N=L+1;
        int a[N],b[M],c[M];
        for(int i=0;i<N;i++)
        {
            a[i]=i;   //��ʼ������·
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&b[i],&c[i]);//����������ֱ����洢�������β
        }
        for(int i=0;i<M;i++)
        {
            for(int j=b[i];j<=c[i];j++)
            {
                a[j]=-1;//�Ѱε���������ǳ�-1
            }
        }
        for(int i=0;i<N;i++)
        {
            if(a[i]!=-1)
            {
                count++;//������δ���ε�����������
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
