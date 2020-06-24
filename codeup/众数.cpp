#include<cstdio>
int main()
{
    int a[20];
    while(scanf("%d",&a[0])!=EOF)
    {
        int hashtable[15]={0};
        hashtable[a[0]]++;
        for(int i=1;i<20;i++)
        {
            scanf("%d",&a[i]);
            hashtable[a[i]]++;
        }
        int m=0;
        for(int i=1;i<11;i++)
        {
            if(hashtable[a[i]]>hashtable[m])
            {
                m=a[i];
            }
        }
        /*for(int i=0;i<15;i++)
        {
            printf("%d\n",hashtable[i]);
        }*/
        printf("%d\n",m);
    }
    return 0;
}
