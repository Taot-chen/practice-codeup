#include<stdio.h>
#include<string.h>
struct stu
{
    int num;
    char name[200];
    char gender[20];
    int age;
} a[20];
int main()
{
    int m,n,b;
    scanf("%d",&m);
    for(int k=0;k<m;k++)
    {
        //int maxn=20;
        //struct stu a[maxn];
        //int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %s %s %d",&((a+i)->num),&((a+i)->name),&((a+i)->gender),&((a+i)->age));
        }
        //int b;
            scanf("%d",&b);
            for(int j=0;j<n;j++)
            {
                if(b==a[j].num)
                {
                    printf("%d %s %s %d\n",(a+j)->num,(a+j)->name,(a+j)->gender,(a+j)->age);
                    break;
                }
            }
    }
    return 0;
}
