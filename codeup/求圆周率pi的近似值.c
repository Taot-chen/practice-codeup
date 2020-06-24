#include<stdio.h>
#include<math.h>
int main ()
{
    int i=0;
    double PI=0;
    while(i>=0)
    {
        PI+=(1.0/(2*i+1))*pow((-1),i);
        i++;
        if(fabs((1.0/(2*i+1))<0.000001))
        break;
    }
    printf("PI=%10.8f\n",4*PI);
    return 0;
}
