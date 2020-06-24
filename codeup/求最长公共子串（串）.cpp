#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL p=1e7+19;
const LL maxn=2010;

LL powp[maxn];
LL H1[maxn]={0};
LL H2[maxn]={0};
struct node
{
    int hashvalue,length;
    int st,ed;
    node(int _hashvalue,int _length,int _st, int _ed):hashvalue(_hashvalue),length(_length),st(_st),ed(_ed) {};
};
vector<node> pr1,pr2;
string str1,str2;

//初始化数组powp
void init(int len)
{
    powp[0]=1;
    for(int i=1;i<=len;i++)
    {
        powp[i]=(powp[i-1]*p)%MOD;
    }
}

//计算字符串str的hash值
void calH(LL H[],string &str)
{
    H[0]=str[0];
    for(int i=1;i<str.length();i++)
    {
        H[i]=(H[i-1]*p+str[i])%MOD;
    }
}

//计算H[i……j]
int calsinglesubH(LL H[],int i,int j)
{
    if(i==0)
    {
        return H[j];
    }
    return (H[j]-H[i-1]*powp[j-(i-1)]%MOD+MOD)%MOD;
}

//计算所有子串的hash值
void calsubH(LL H[],int len,vector<node> &pr)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            int hashvalue=calsinglesubH(H,i,j);
            pr.push_back(node(hashvalue,j-i+1,i,j));
        }
    }
}

//找出最大公共子串
string getmax()
{
    string str;
    int ans=0;
    for(int i=0;i<pr1.size();i++)
    {
        for(int j=0;j<pr2.size();j++)
        {
            if(pr1[i].hashvalue==pr2[j].hashvalue)
            {
                if(ans<pr1[i].length)
                {
                    ans=pr1[i].length;
                    str=str1.substr(pr1[i].st,pr1[i].ed);
                }

            }
        }
    }
    return str;
}
int main()
{
    //string str1,str2;
    while(getline(cin,str1))
    {
        getline(cin,str2);
        init(max(str1.length(),str2.length()));
        calH(H1,str1);
        calH(H2,str2);
        calsubH(H1,str1.length(),pr1);
        calsubH(H2,str2.length(),pr2);
        string res=getmax();
        if(res.length()==0)
        {
            printf("false\n");
        }
        else
        {
            cout<<res<<endl;
        }
    }
    return 0;
}
