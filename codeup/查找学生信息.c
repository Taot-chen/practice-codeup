#include<stdio.h>
#include<string.h>
int main()
{
    int maxn=1000;
    int n,m;
    //scanf("%d",&n);
    while(scanf("%d",&n)!=EOF)
    {
        struct stu
    {
        char num[5];
        char name[10];
        char gender[5];
        int age;
    };
    struct stu a[maxn];
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %s %d",&((a+i)->num),&((a+i)->name),&((a+i)->gender),&((a+i)->age));
    }
    /*for(int i=0;i<n;i++)
    {
        printf("%s %s %s %d\n",(a+i)->num,(a+i)->name,(a+i)->gender,(a+i)->age);
    }*/
    scanf("%d",&m);
    char b[m][10];
    for(int i=0;i<m;i++)
    {
        scanf("%s",b[i]);
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(strcmp(b[i],a[j].num)==0)
            {
                printf("%s %s %s %d\n",a[j].num,a[j].name,a[j].gender,a[j].age);
                k++;
            }
        }
        if(!k)
        {
            printf("No Answer!\n");
        }
    }
    /*for(int i=0;i<m;i++)
    {
        printf("%s\n",b[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",a[i].num);
    }*/
    }

    return 0;
}
