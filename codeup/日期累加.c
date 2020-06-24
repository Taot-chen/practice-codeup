#include<stdio.h>
int panduan(int year)
{
    return((year%4==0&&year%100!=0)||(year%400==0));
}
int A[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

int main()
{
    int M,y,m,d,n;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d%d",&y,&m,&d,&n);
        for(int j=0;j<n;j++)
        {
            d++;
            if(d==A[m][panduan(y)]+1)
            {
                d=1;
                m++;
            }
            if(m==13)
            {
                m=1;
                y++;
            }
        }
        printf("%04d-%02d-%02d\n",y,m,d);
    }
    return 0;
}
