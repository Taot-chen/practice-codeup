#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;
bool check(char a)
{
    if(a>='a'&&a<='z'||a>='A'&&a<='Z'||a>='0'&&a<='9')
    {
        return true;
    }
    return false;
}
int main()
{
    string str;
    string word;
    map<string,int> mp;
    while(getline(cin,str))
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            if(check(str[i]))
            {
                word+=str[i];
            }
            if(!check(str[i])||i==str.length()-1)
            {
                if(word.length()!=0)
                mp[word]++;
                word.clear();
            }
        }
        int max=-1;
        string res;
        for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>max)
            {
                max=it->second;
                res=it->first;
            }
        }
        //printf("%s %d\n",res,max);
        cout<<res<<' '<<max<<endl;
    }
    return 0;
}
