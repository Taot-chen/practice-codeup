#include<stdio.h>
void input(int a[])
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",a+i);
    }
}
void exchange(int a[])
{
    int small,big,temp;
    int max=*(a+0);
    int min=max;
    for(int i=0;i<10;i++)
    {
        if(max<*(a+i))
        {
            max=*(a+i);
            big=i;
        }
        if(min>*(a+i))
        {
            min=*(a+i);
            small=i;
        }
    }
    temp=*(a+0);
    *(a+0)=min;
    *(a+small)=temp;
    temp=*(a+9);
    *(a+9)=max;
    *(a+big)=temp;
}
void output(int a[])
{
    for(int i=0;i<10;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
}
int main()
{
    int a[10];
    input(a);
    exchange(a);
    output(a);
    return 0;
}
