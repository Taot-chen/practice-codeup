#include<stdio.h>
#include<string.h>
int panduan(int year)
{
    return((year%4==0&&year%100!=0)||(year%400==0));
}
char Weekday[8][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","0"};
char Month[13][20]={"0","January", "February","March","April","May","June","July","August","September","October","November","December"};
int A[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

int main()
{
    int d,y;
    char month[20];
    while(scanf("%d %s %d",&d,month,&y)!=EOF)
    {

        //把月份转换成整型处理
        int m;
        for(int i=1;i<13;i++)
        {
            if(strcmp(month,Month[i])==0)
            {
                m=i;
            }
        }

        //从公元元年开始数，到指定日期有多少天
        int sum=0,d1=1,y1=1,m1=1;
        for(int i=1;i<y;i++)//先利用年份累加到指定日期的前一年
        {
            if(panduan(i))
            {
                sum+=366;
            }
            else sum+=365;
            y1++;
        }
        while(y1<y||m1<m||d1<d)
        {
            d1++;
            if(d1==A[m1][panduan(y1)]+1)
            {
                m1++;
                d1=1;
            }
            if(m1==13)
            {
                y1++;
                m1=1;
            }
            sum++;
        }
        sum++;
        int weekd=sum%7;//由于公元元年一月一日周日，那么余数为零就是周日
        printf("%s\n",Weekday[weekd]);
    }
    return 0;
}
