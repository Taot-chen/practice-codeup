#include<cstdio>
int main()
{
    for(int i=1000;i<1112;i++)
    {
        int a=i/1000+i/10%10*100+i/100%10*10+i%10*1000;
        //printf("%d\n",a);
        if(a==9*i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
