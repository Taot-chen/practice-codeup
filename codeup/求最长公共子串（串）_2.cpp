#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int maxn=1010;
const LL p=1e7+19;
const LL mod=1e9+7;
LL powP[maxn],H1[maxn]={0},H2[maxn]={0};

struct Node
{
	int hashValue,length,start,end;
	Node(int a,int b,int c,int d):hashValue(a),length(b),start(c),end(d){};
};
vector<Node> pr1,pr2;
void init(int len)
{
	powP[0]=1;
	for(int i=1;i<=len;++i)
	{
		powP[i]=(powP[i-1]*p)%mod;
	}
}
void calH(LL H[],string &str)
{
	H[0]=str[0];
	for(int i=1;i<str.length();++i)
	{
		H[i]=(H[i-1]*p+str[i])%mod;
	}
}
int calSingleSubH(LL H[],int i,int j)
{
	if(i==0)
		return H[j];
	return ((H[j]-H[i-1]*powP[j-i+1])%mod+mod)%mod;
}
void calSubH(LL H[],int len,vector<Node> &p)
{
	for(int i=0;i<len;++i)
		for(int j=i;j<len;++j)
		{
			int value=calSingleSubH(H,i,j);
			p.push_back(Node(value,j-i+1,i,j));
		}
}
string getMax(string str1)
{
	string str;
	int ans=0;
	for(int i=0;i<pr1.size();++i)
		for(int j=0;j<pr2.size();++j)
		{
			if(pr1[i].hashValue==pr2[j].hashValue)
			{
				if(pr1[i].length>ans)
				{
					ans=pr1[i].length;
					str=str1.substr(pr1[i].start,pr1[i].end);
				}
			}
		}
	return str;
}
int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	init(max(str1.length(),str2.length()));
	calH(H1,str1);
	calH(H2,str2);
	calSubH(H1,str1.length(),pr1);
	calSubH(H2,str2.length(),pr2);
	cout<<getMax(str1)<<endl;
	return 0;
}
