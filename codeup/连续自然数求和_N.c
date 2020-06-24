#include<stdio.h>
int main()
{
    int i=1,N, sum=0;
    scanf("%d",&N);
    while (i>0)
    {
        sum+=i;
        i++;
        if(i>N)
            break;
    }
    printf("%d\n",sum);
    return  0;
}
