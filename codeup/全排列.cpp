#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        do
        {
            cout<<str<<endl;
        }while(next_permutation(str.begin(),str.end()));
        cout<<endl;
    }
    return 0;
}
