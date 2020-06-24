#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}
