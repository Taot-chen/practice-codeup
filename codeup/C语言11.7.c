#include<stdio.h>
struct chengji
{
    int num;
    char name[20];
    int fenshu1;
    int fenshu2;
    int fenshu3;
};
void input(struct chengji data[5])
{
    for(int i=0;i<5;i++)
    {
        scanf("%d %s %d %d %d",&data[i].num,data[i].name,&data[i].fenshu1,&data[i].fenshu2,&data[i].fenshu3);
    }
}
void print(struct chengji data[5])
{
    for(int i=0;i<5;i++)
    {
        printf("%d %s %d %d %d\n",data[i].num,data[i].name,data[i].fenshu1,data[i].fenshu2,data[i].fenshu3);
    }
}
int main()
{
    struct chengji data[5];
    //struct chengji *p;
    //p=data;
    input(data);
    print(data);
    return 0;
}
