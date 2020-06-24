#include<stdio.h>
#include<string.h>
int n;

void change(char c[])
{
    int i;
    char b[15];
    for(i=0;i<n;i++)
    {
        b[i]=c[n-1-i];
    }
    for(i=0;i<n;i++)
    {
        printf("%c",b[i]);
    }
    printf("\n");

}
int main()
{
    int i;

    char a[15];
    scanf("%s",a);
    n=strlen(a);
    //printf("n=%d\n",n);
    change(a);
    //for(i=0;i<n;i++)
    //{
    //    printf("%c",a[i]);
    //}
    //printf("\n");
    return 0;
}
