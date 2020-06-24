#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[100];

    int A,B;
    int sum;
    int m,n,j,k;
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        char a[100]={0},b[100]={0};
        m=strlen(str1);
        n=strlen(str2);
        j=0;
        k=j;
        sum=0;
        for(int i=0;i<m;i++)
        {
            if(str1[i]!=',')
            {
                a[j++]=str1[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(str2[i]!=',')
            {
                b[k++]=str2[i];
            }
        }

        //printf("%s\n%s\n",a,b);
        sscanf(a,"%d",&A);
        sscanf(b,"%d",&B);
        //printf("%d %d",A,B);
        sum=A+B;
        printf("%d\n",sum);
    }
    return 0;
}
