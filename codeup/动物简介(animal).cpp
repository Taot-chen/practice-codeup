#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=3010;
const int maxl=260;
string text;
string pattern;
int nextval[maxn*maxl];

void getnextval(string s,int len)
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
        if(j==-1||s[i+1]!=s[j+1])
        {
            nextval[i]=j;
        }
        else
        {
            nextval[i]=nextval[j];
        }
    }
}

int kmp(string tex,string pattern)
{
    int n=tex.length();
    int m=pattern.length();
    int ans=0;
    int j=-1;
    //getnextval(pattern,m);
    for(int i=0;i<n;i++)
    {
        while(j!=-1&&tex[i]!=pattern[j+1])
        {
            j=nextval[j];
        }
        if(tex[i]==pattern[j+1])
        {
            j++;
        }
        if(j==m-1)
        {
            ans++;
            j=nextval[j];
        }
    }
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        getline(cin,pattern);
        int m=pattern.length();
        getnextval(pattern,m);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            getline(cin,text);
            ans+=kmp(text,pattern);

        }
        printf("%d\n",ans);
    }
    return 0;
}
