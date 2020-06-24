#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    //printf("%d\n",n);
    struct person
    {
        char name[20];
        int count;
    } leader[3]={"Li",0,"Zhang",0,"Fun",0};
    char str[n][20];
    for(int i=0;i<n+1;i++)
    {
        gets(str[i]);
    }

    //for(int i=0;i<n;i++)
    //{
    //    puts(str[i]);
    //}
    for(int i=0;i<n+1;i++)
    {
        if(strcmp(str[i],leader[0].name)==0)
        {
            leader[0].count++;
        }
        else if(strcmp(str[i],leader[1].name)==0)
        {
            leader[1].count++;
        }
        else if(strcmp(str[i],leader[2].name)==0)
        {
            leader[2].count++;
        }
    }
    for(int i=0;i<3;i++)
    {
        printf("%s:%d\n",leader[i].name,leader[i].count);
    }
    return 0;
}
