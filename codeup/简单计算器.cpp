#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<stack>
using namespace std;
//�����������б�����׺���ʽ��ȥ�����еĿո񣬴����ԭ�ַ�����
//�ٽ�ȥ���ո����׺���ʽת��Ϊ��׺���ʽ������ڶ�����
//������ջ�������׺���ʽ����������
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
void change()//��ȥ���ո����׺���ʽת��Ϊ��׺���ʽ������ڶ�����
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
double cal()//����ջ�������׺���ʽ
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
        //ȥ����׺���ʽ����Ŀո�
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
