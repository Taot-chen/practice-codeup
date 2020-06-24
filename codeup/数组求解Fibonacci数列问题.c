#include<stdio.h>
int main()
{
    int n=20,F[100],i;
    for(i=0;i<n;i++)
    {
       if(i==0||i==1)
       {
           F[i]=1;
       }
       else
       {
           F[i]=F[i-1]+F[i-2];
       }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",F[i]);
    }
    return 0;
}
