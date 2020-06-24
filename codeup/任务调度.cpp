#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
struct Task
{
    string name;
    int num;
    friend bool operator(const Task &t1,const Task &t2)/*����<��ʹ���ȶ����ڵ�������*/
    {
        if(t1.num!=t2.num)
        {
            return t1.num>t2.num;
        }
        else
        {
            return t1.name>t2.name;
        }
    }
};
void solve(string s,priority_queue<Task> &task,map<string,int> &mp)
{
    //ȡ����һ��task��������浽��������
    int pos=s.find('(');
    int firstnum;
    string first=s.substr(0,pos);
    s.erase(0,pos+1);
    if(mp.count(first)==0)//������û��first
    {
        Task ntask;
        ntask.name=fist;
        ntask.num=0;
        task.push(ntask);
        firstnum=mp[first]=0;
    }
    else//�������Ѿ�����irst,ֱ�Ӵ���
    {
        firstnum=mp[first];
    }

    //ȡ����һ��task��ֱ�����һ����������������
    while(!(s.empty()))//�����ж��Ƿ����
    {
        string next;
        pos=s.find(',');
        if(pos==string::npos)
        {
            pos=s.find(')');
            next=s.substr(0,pos);
            s.clear();
        }
        else
        {
            next=s.substr(0,pos);
            s.erase(0,pos+1);
        }
        if(next!="NULL")
        {
            Task ntask;
            ntask.name=next;
            ntask.num=firstnum+1;
            mp[next]=ntask.num;
            task.push(ntask);
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        string str;
        map<string,int> mp;
        priority_queue<Task> task;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            solve(str,task,mp);//һ��һ�еش���
        }
        while(task.empty()==false)
        {
            cout<<task.top().name;
            task.pop();
            if(task.empty()==false)
            {
                cout<<" ";
            }
        }
        cout<<"\n";
        mp.clear();
    }
    return 0;
}
