#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<stack>
using namespace std;
//现在主函数中遍历中缀表达式，去掉其中的空格，存放在原字符串中
//再将去掉空格的中缀表达式转换为后缀表达式，存放在队列中
//再利用栈来计算后缀表达式，并输出结果
struct node
{
    double num;
    char op;
    bool flag;
};
string str;
stack<node> s;
map<char,int> mp;
queue<node> q;
void change()//将去掉空格的中缀表达式转换为后缀表达式，存放在队列中
{
    double num;
    node temp;
    for(int i=0;i<str.length();)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            temp.flag=true;
            temp.num=str[i++]-'0';
            while(i<str.length()&&str[i]>='0'&&str[i]<='9')
            {
                temp.num=temp.num*10+str[i]-'0';
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag=false;
            while(!s.empty()&&mp[str[i]]<=mp[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
double cal()//利用栈来计算后缀表达式
{
    double temp1,temp2;
    node temp;
    node first;
    while(!q.empty())
    {
        first=q.front();
        q.pop();
        if(first.flag==true)
        {
            s.push(first);
        }
        else
        {
            temp2=s.top().num;
            s.pop();
            temp1=s.top().num;
            s.pop();
            temp.flag=true;
            if(first.op=='+') temp.num=temp1+temp2;
            else if(first.op=='-') temp.num=temp1-temp2;
            else if(first.op=='*') temp.num=temp1*temp2;
            else temp.num=temp1/temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}
int main()
{
    mp['+']=mp['-']=1;
    mp['*']=mp['/']=2;
    while(getline(cin,str),str!="0")
    {
        //去掉中缀表达式里面的空格
        for(string::iterator it=str.end();it!=str.begin();it--)
        {
            if(*it==' ')
            {
                str.erase(it);
            }
        }
        while(!s.empty())
        {
            s.pop();
        }
        change();
        double res=cal();
        printf("%.2f\n",res);
    }
    return 0;
}
