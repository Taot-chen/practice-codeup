#include<stdio.h>
struct school
{
    int num;
    char name[10];
    char sex;
    char job;
    union
    {
        int clas;
        char position[10];
    } category;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct school data[n];
    struct school *p;
    p=data;
    for(int i=0;i<n;i++)
    {
        scanf("%d %s %c %c",&(p+i)->num,&(p+i)->name,&(p+i)->sex,&(p+i)->job);
        if((*(p+i)).job=='s')
        {
            scanf("%d",&(p+i)->category.clas);
        }
        else if ((*(p+i)).job=='t')
        {
            scanf("%s",&(p+i)->category.position);
        }
    }
    //printf("%s\n",(*(p+1)).category.position);
    for(int i=0;i<n;i++)
    {
        printf("%d %s %c %c",(*(p+i)).num,(*(p+i)).name,(*(p+i)).sex,(*(p+i)).job);
        if((*(p+i)).job=='s')
        {
            printf(" %d\n",(p+i)->category.clas);
        }
        else if ((*(p+i)).job=='t')
        {
            printf(" %s\n",(*(p+i)).category.position);
        }
    }
    return 0;
}
