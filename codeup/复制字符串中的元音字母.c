#include<stdio.h>
#include<string.h>
int n;
void vowels(char s1[], char s2[])
{
    int i;
    int j=0;
    for(i=0;i<n;i++)
    {
        if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'||s1[i]=='A'||s1[i]=='E'||s1[i]=='I'||s1[i]=='O'||s1[i]=='U')
        {
            s2[j]=s1[i];
            j++;
        }

    }

    int m=strlen(s2);
    //printf("%d\n",m);
    for(i=0;i<m;i++)
    {
        printf("%c",s2[i]);
    }
    printf("\n");
}
int main()
{
    char s1[100];
    char s2[100];
    scanf("%s",s1);
    n=strlen(s1);
    //for(int i=0;i<n;i++)
    //{
    //    printf("%c",s1[i]);
    //}
    //printf("\n");
    vowels(s1,s2);
    return 0;
}
