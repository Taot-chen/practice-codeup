#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1000010;
string text;
string pattern;
int nextval[maxn];
int st;
bool flag=false;

void change(string &str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]+=32;
        }
    }
}

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
    getnextval(pattern,m);
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
            if(i-m>=0&&i<n-1&&tex[i+1]==' '&&tex[i-m]==' '||i-m+1==0&&i<n-1&&tex[i+1]==' '||i-m>=0&&i==n-1&&tex[i-m]==' '||i-m+1==0&&i==n-1)
            {
                ans++;
                if(!flag)
                {
                    flag=true;
                    st=i-m+1;
                }
            }
            j=nextval[j];
        }
    }
    return ans;
}

int main()
{
    while(getline(cin,pattern))
    {
        flag=false;
        getline(cin,text);
        change(text);
        change(pattern);
        int res=kmp(text,pattern);
        if(res==0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n",res,st);
        }
    }
    return 0;
}
