#include<cstdio>
#include<unordered_map>
#include<string>
#include<stack>
#include<iostream>
using namespace std;
void solve(string str,unordered_map<char,int> mp)
{
    stack<char> s;
    for(string::iterator it=str.begin();it!=str.end();it++)
    {
        if(mp.count(*it))
        {
            if(s.empty()==false)
            {
                if(mp[*it]+mp[s.top()]==5)
                {
                    s.pop();
                }
                else
                {
                    if(mp[*it]<=2)
                    {
                        s.push(*it);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                s.push(*it);
                if(mp[*it]>2)
                {
                    break;
                }
            }
        }
    }
    if(s.empty()==false)
    {
        printf("no\n");
    }
    else printf("yes\n");
}
int main()
{
    int n;
    unordered_map<char,int> mp;
    mp['(']=0;
    mp['[']=1;
    mp['{']=2;
    mp['}']=3;
    mp[']']=4;
    mp['(']=5;
    while(scanf("%d",&n)!=EOF)
    {
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            solve(str,mp);
        }
    }
    return 0;
}
