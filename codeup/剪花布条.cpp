#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1010;
char text[maxn];
char pattern[maxn];
int nextval[maxn];

void getnextval(char s[],int len)
{
    int j=-1;
    nextval[0]=-1;
    for(int i=1;i<len;i++)
    {
        while(j!=-1&&s[i]!=s[j+1])
        {
            j=nextval[j];
        }
        if(s[i]==s[j+1])
        {
            j++;
        }
        if(j==-1||s[i]!=s[j+1])
        {
            nextval[i]=j;
        }
        else
        {
            nextval[i]=nextval[j];
        }
    }
}

int kmp(char s1[],char s2[])
{
    int n=strlen(s1);
    int m=strlen(s2);
    int ans=0;
    int j=-1;
    getnextval(s2,m);
    for(int i=0;i<n;i++)
    {
        while(j!=-1&&s1[i]!=s2[j+1])
        {
            j=nextval[j];
        }
        if(s1[i]==s2[j+1])
        {
            j++;
        }
        if(j==m-1)
        {
            ans++;
            j=-1;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%s",text)!=EOF)
    {
        if(strlen(text)==1&&text[0]=='#')
        {
            break;
        }
        scanf("%s",pattern);
        int res=kmp(text,pattern);
        printf("%d\n",res);
    }
    return 0;
}
