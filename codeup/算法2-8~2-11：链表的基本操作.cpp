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
node *creat(int n)//创建链表，并输入
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
void get(node *head,int a)//查找并输出
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
void inser_t(node *head,int a,int e)//插入
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
void delet_e(node *head,int a)//删除
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
void show(node *head)//输出
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
        getchar();//读入m后面的换行符
        string str;
        for(int i=0;i<m;i++)
        {
            getline(cin,str);
            //getchar();//由于getline(cin,str)不会读入行末的换行符，为了顺利读入多行，此处单独读入换行符
            //下面开始判断需要执行的操作
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
