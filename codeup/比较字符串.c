#include<stdio.h>
const int maxn=55;
int main()
{
    int m;
    char a[maxn],b[maxn];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%s %s",a,b);
        int j=0,k=0;
        while(a[j]!='\0')
        {
            j++;
        }
        while(b[k]!='\0')
        {
            k++;
        }
        if(j==k)
        {
            printf("%s is equal long to %s\n",a,b);
        }
        else if(j>k)
        {
            printf("%s is longer than %s\n",a,b);
        }
        else printf("%s is shorter than %s\n",a,b);
    }
    return 0;
}
