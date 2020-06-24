#include<stdio.h>
struct stu
{
    int num;
    char name[20];
    int fenshu1;
    int fenshu2;
    int fenshu3;
};
int main()
{
    struct stu data[10];
    struct stu *p;
    p=data;
    double a[10];
    int total1=0,total2=0,total3=0;
    double ta1,ta2,ta3;
    int n,za;
    za=0;
    n=0;
    for(int i=0;i<10;i++)
    {
        scanf("%d %s %d %d %d",&(p+i)->num,&(p+i)->name,&(p+i)->fenshu1,&(p+i)->fenshu2,&(p+i)->fenshu3);
    }
    for(int i=0;i<10;i++)
    {
        a[i]=((p+i)->fenshu1+(p+i)->fenshu2+(p+i)->fenshu3)/3.0;
        total1+=(p+i)->fenshu1;
        total2+=(p+i)->fenshu2;
        total3+=(p+i)->fenshu3;
    }
    for(int i=0;i<10;i++)
    {
        if(za<a[i])
        {
            za=a[i];
            n=i;
        }
    }
    ta1=total1/10.0;
    ta2=total2/10.0;
    ta3=total3/10.0;
    printf("%.2lf %.2lf %.2lf\n%d %s %d %d %d\n",ta1,ta2,ta3,data[n].num,data[n].name,data[n].fenshu1,data[n].fenshu2,data[n].fenshu3);
    return 0;
}
