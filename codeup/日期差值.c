#include<stdio.h>
int panduan(int year)
{
    return((year%4==0&&year%100!=0)||(year%400==0));
}
    int a[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
int main()
{
    int time1,time2;
    int y1,m1,d1,y2,m2,d2;
    while(scanf("%d%d",&time1,&time2)!=EOF)
    {
        if(time1>time2)
        {
            int temp=time1;
            time1=time2;
            time2=temp;
        }
        y1=time1/10000;
        m1=(time1%10000)/100;
        d1=time1%100;
        y2=time2/10000;
        m2=(time2%10000)/100;
        d2=time2%100;
        int count=1;
        while(y1<y2||m1<m2||d1<d2)
        {
            d1++;
            if(d1==a[m1][panduan(y1)]+1)
            {
                m1++;
                d1=1;
            }
            if(m1==13)
            {
                y1++;
                m1=1;
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
