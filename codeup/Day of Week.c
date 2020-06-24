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

        //���·�ת�������ʹ���
        int m;
        for(int i=1;i<13;i++)
        {
            if(strcmp(month,Month[i])==0)
            {
                m=i;
            }
        }

        //�ӹ�ԪԪ�꿪ʼ������ָ�������ж�����
        int sum=0,d1=1,y1=1,m1=1;
        for(int i=1;i<y;i++)//����������ۼӵ�ָ�����ڵ�ǰһ��
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
        int weekd=sum%7;//���ڹ�ԪԪ��һ��һ�����գ���ô����Ϊ���������
        printf("%s\n",Weekday[weekd]);
    }
    return 0;
}
