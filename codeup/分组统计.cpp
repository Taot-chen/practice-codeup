#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int hashtable1[100010]={0},hashtable2[100010]={0};
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        for(int k=0;k<m;k++)
        {
            int n;
            scanf("%d",&n);

            //�����һ�����ֲ�ȥ�أ�ȥ����Ϊ���������ʱ�򷽱�ʹ��ѭ����
            int a[n]={0};
            int b[n]={0};
            int z=0,maxa=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                if(hashtable1[a[i]]==0)//ȥ��
                {
                    hashtable1[a[i]]++;
                    b[z++]=a[i];
                }
                if(maxa<a[i])//�ҳ���һ�����е����ֵ
                {
                    maxa=a[i];
                }
            }
            sort(b,b+z);//����

            //����ڶ������ֲ�ȥ��
            int c[n]={0};
            int d[n]={0};
            int y=0,maxc=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&c[i]);
                if(hashtable2[c[i]]==0)//ȥ��
                {
                    hashtable2[c[i]]++;
                    d[y++]=c[i];
                }
                if(maxc<c[i])//�ҳ��ڶ������е����ֵ
                {
                    maxc=c[i];
                }
            }
            sort(d,d+y);//����

            //�ѵ�һ�����ֺ͵ڶ������ִ�ŵ�����result[i][j]�У�i������ţ�j��������
            //result��Ԫ�ش�����Ӧ�����ֳ��ֵĴ���
            int result[maxc+10][maxa+10]={};
            for(int i=0;i<n;i++)
            {
                result[c[i]][a[i]]++;
            }

         //������
         for(int i=0;i<y;i++)
         {
             printf("%d={",d[i]);
             for(int j=0;j<z;j++)
             {
                 printf("%d=%d",b[j],result[d[i]][b[j]]);
                 if(j<z-1)
                 {
                     printf(",");
                 }
                 else printf("}\n");
             }
         }
         /*for(int i=0;i<maxc+10;i++)
         {
             for(int j=0;j<maxa+10;j++)
             {
                 printf("%d ",result[i][j]);
             }
             printf("\n");
         }*/
        }
    }
    return 0;
}
