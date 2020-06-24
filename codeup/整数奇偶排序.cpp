#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int pandaun(int a)
{
    return a%2;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a[10],b[10],c[10];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
    {
        int j=0,k=0;
        for(int i=0;i<10;i++)
        {
            if(pandaun(a[i]))
            {
                b[j++]=a[i];
            }
            else c[k++]=a[i];
        }
        sort(b,b+j,cmp);
        sort(c,c+k);
        for(int i=0;i<j;i++)
        {
            printf("%d ",b[i]);
        }
        for(int i=0;i<k;i++)
        {
            printf("%d",c[i]);
            if(i!=k)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
