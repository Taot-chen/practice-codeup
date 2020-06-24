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

            //输入第一行数字并去重（去重是为了在输出的时候方便使用循环）
            int a[n]={0};
            int b[n]={0};
            int z=0,maxa=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                if(hashtable1[a[i]]==0)//去重
                {
                    hashtable1[a[i]]++;
                    b[z++]=a[i];
                }
                if(maxa<a[i])//找出第一行数中的最大值
                {
                    maxa=a[i];
                }
            }
            sort(b,b+z);//排序

            //输入第二行数字并去重
            int c[n]={0};
            int d[n]={0};
            int y=0,maxc=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&c[i]);
                if(hashtable2[c[i]]==0)//去重
                {
                    hashtable2[c[i]]++;
                    d[y++]=c[i];
                }
                if(maxc<c[i])//找出第二行数中的最大值
                {
                    maxc=c[i];
                }
            }
            sort(d,d+y);//排序

            //把第一行数字和第二行数字存放到数组result[i][j]中，i代表组号，j代表数字
            //result的元素代表相应的数字出现的次数
            int result[maxc+10][maxa+10]={};
            for(int i=0;i<n;i++)
            {
                result[c[i]][a[i]]++;
            }

         //输出结果
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
