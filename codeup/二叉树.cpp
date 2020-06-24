#include<cstdio>
#include<iostream>
#include<cmath>
int index[32];
void num()
{
    for(int i=0;i<31;i++)
    {
        index[i]=(int)pow(2.0,1.0*i);
    }
}
int depth(int x)
{
    int i;
    for(i=0;i<31;i++)
    {
        if(x<index[i])
        {
            return i;
        }
    }
}
int main()
{
    //int index[32];
    int m,n;
    num();
    while(scanf("%d%d",&m,&n),m!=0&&n!=0)
    {
        int dm,dn;
        dm=depth(m);
        dn=depth(n);
        int number=0;
        int i;
        for(i=0;i<dn-dm;i++)
        {
           number+=index[i];
           m*=2;
        }
        if(m<=n)
        {
            if(n-m+1<index[i])
            {
                number+=n-m+1;
            }
            else
            {
                number+=index[i];
            }
        }
        printf("%d\n",number);
    }
    return 0;
}
