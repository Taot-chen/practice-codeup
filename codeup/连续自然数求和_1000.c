#include<stdio.h>
int main()
{
    int i=1,N, sum=0;
    while (i>0)
    {
        sum+=i;
        if(sum>1000)
            break;
        i++;

    }
    N=i;
    printf("%d\n",N);
    return  0;
}
