#include<cstdio>
#include<iostream>
using namespace std;
int n,cnt;
void f(int num,int po,int pu)//num��ʾջ��ʣ���Ԫ��������po��ʾʣ��pop������������pu��ʾʣ��push����������
{
    if(!po&&!pu)
    {
        cnt++;
    }
    if(po&&num)//����ִ��pop����������
    {
        f(num-1,po-1,pu);//ִ��һ��pop֮��Ľ����������һ��
    }
    if(pu)
    {
        f(num+1,po,pu-1);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        f(0,n,n);//�ڸտ�ʼ��ջ���ǿյģ�pop��push�����Բ���n��
        cout<<cnt<<endl;
    }
    return 0;
}
