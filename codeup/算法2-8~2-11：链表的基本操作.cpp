#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *creat(int n)//��������������
{
    node *L;
    L=new node;
    L->next=NULL;
    int a;
    node *p;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        p=new node;
        p->data=a;
        p->next=L->next;
        L->next=p;
    }
    return L;
}
void get(node *head,int a)//���Ҳ����
{
    node *p=head ;
    for(int i=0;i<a;i++)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("get fail\n");
    }
    else
    {
        printf("%d\n",p->data);
    }
}
void inser_t(node *head,int a,int e)//����
{
    node *p=head;
    for(int i=0;i<a-1;i++)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("insert fail\n");
    }
    else
    {
        node *pre=new node;
        pre->data=e;
        pre->next=p->next;
        p->next=pre;
        printf("insert OK\n");
    }
}
void delet_e(node *head,int a)//ɾ��
{
    node *pre=head;
    node *p=head->next;
    if(p==NULL)
    {
        printf("delete fail\n");
    }
    else
    {
        for(int i=0;i<a-1;i++)
        {
            pre=p;
            p=pre->next;
        }
        if(p==NULL)
        {
            printf("delete fail\n");
        }
        else
        {
            pre->next=p->next;
            delete(p);
            printf("delete OK\n");
        }
    }
}
void show(node *head)//���
{
    node *p=head->next;
    if(p==NULL)
    {
        printf("Link list is empty\n");
    }
    while(p!=NULL)
    {
        if(p->next==NULL)
        {
            printf("%d\n",p->data);
        }
        else
        {
            printf("%d ",p->data);
        }
        p=p->next;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        node *head=creat(n);
        int m;
        scanf("%d",&m);
        getchar();//����m����Ļ��з�
        string str;
        for(int i=0;i<m;i++)
        {
            getline(cin,str);
            //getchar();//����getline(cin,str)���������ĩ�Ļ��з���Ϊ��˳��������У��˴��������뻻�з�
            //���濪ʼ�ж���Ҫִ�еĲ���
            if(str[0]=='g')
            {
                str.erase(0,4);
                get(head,str[0]-'0');
            }
            else if(str[0]=='i')
            {
                str.erase(0,7);
                int a=str[0]-'0';
                str.erase(0,2);
                int b=str[0]-'0';
                inser_t(head,a,b);
            }
            else if(str[0]=='d')
            {
                str.erase(0,7);
                delet_e(head,str[0]-'0');
            }
            else if(str[0]=='s')
            {
                show(head);
            }
            else
            {
                printf("error!\n");
            }
        }
    }
    return 0;
}
